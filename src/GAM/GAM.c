/****************************************************************************
 *
 * GAM - Main engine module
 *
 ****************************************************************************/

#include "GAM.h"
#include "GAM_ObjType.h"


/****************************************************************************
 * GAM.h
 ****************************************************************************/

/* Engine structure */
GAM_tdstEngineStructure *const GAM_g_stEngineStructure = OFFSET(0x500380);
char const *const GAM_g_szCmdLine = OFFSET(0x4E0DA0);

HIE_tdstSuperObject **const GAM_g_p_stDynamicWorld = OFFSET(0x0500FD0);
HIE_tdstSuperObject **const GAM_g_p_stInactiveDynamicWorld = OFFSET(0x500FC4);
HIE_tdstSuperObject **const GAM_g_p_stFatherSector = OFFSET(0x500FC0);

unsigned char *const GAM_g_ucIsEdInGhostMode = OFFSET(0x500370);
char *const GAM_g_cIsLevelOk = OFFSET(0x500371);


GAM_tdeEngineMode (*GAM_fn_ucGetEngineMode)( void ) = OFFSET(0x404C60);
void (*GAM_fn_vChangeEngineMode)( GAM_tdeEngineMode ucMode ) = OFFSET(0x404BF0);

void (*GAM_fn_vInitEngineWhenInitApplication)( void ) = OFFSET(0x401000);
void (*GAM_fn_vFirstInitEngine)( void ) = OFFSET(0x403430);
void (*GAM_fn_vInitGameLoop)( void ) = OFFSET(0x4030C0);
void (*GAM_fn_vInitLevelLoop)( void ) = OFFSET(0x403730);
void (*GAM_fn_vChooseTheGoodInit)( void ) = OFFSET(0x404700);
void (*GAM_fn_vChooseTheGoodDesInit)( void ) = OFFSET(0x404940);
void (*GAM_fn_vEngine)( void ) = OFFSET(0x40ADA0);

void (*GAM_fn_vSetEngineInPaused)( void ) = OFFSET(0x405CC0);
void (*GAM_fn_vResetEngineFromPaused)( void ) = OFFSET(0x405CE0);
void (*GAM_fn_vSaveEngineClock)( void ) = OFFSET(0x409E90);
void (*GAM_fn_vLoadEngineClock)( void ) = OFFSET(0x409F00);
void (*GAM_fn_vActualizeEngineClock)( void ) = OFFSET(0x409DD0);

char * (*GAM_fn_p_szGetLevelName)( void ) = OFFSET(0x404DA0);
void (*GAM_fn_vSetLevelName)( char const *szName ) = OFFSET(0x404D00);
char * (*GAM_fn_p_szGetNextLevelName)( void ) = OFFSET(0x404DF0);
void (*GAM_fn_vSetNextLevelName)( char const *szName ) = OFFSET(0x404DC0);
char * (*GAM_fn_p_szGetFirstLevelName)( void ) = OFFSET(0x404CF0);
void (*GAM_fn_vSetFirstLevelName)( char const *szName ) = OFFSET(0x404CC0);
void (*GAM_fn_vAskToChangeLevel)( char const *szLevelName, ACP_tdxBool bSaveGame ) = OFFSET(0x4054D0);

HANDLE (*GAM_fn_hGetWindowHandle)( void ) = OFFSET(0x401400);
BOOL (*GAM_fn_bCreateMainWindow)( HANDLE hInstance, int nShowCmd ) = OFFSET(0x402020);
long (CALLBACK *GAM_fn_WndProc)( HANDLE hWnd, unsigned int uMsg, unsigned int wParam, long lParam ) = OFFSET(0x4022D0);


/****************************************************************************
 * GAM_ObjType.h
 ****************************************************************************/

GAM_tdstObjectType *const GAM_g_stObjectTypes = OFFSET(0x5013E0);
