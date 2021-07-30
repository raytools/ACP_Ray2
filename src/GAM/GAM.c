#include "GAM.h"


///////////////////////
//
// GAM - Game Library
// 
///////////////////////


ACP_API BYTE *const GAM_p_eEngineMode = 0x500380;
ACP_API BYTE *const GAM_p_bEngineFrozen = 0x500FAA;


ACP_API BYTE (*GAM_fn_ucGetEngineMode)( void ) = 0x404C60;
ACP_API void (*GAM_fn_vChangeEngineMode)( BYTE ucMode ) = 0x404BF0;
ACP_API char * (*GAM_fn_p_szGetLevelName)( void ) = 0x404DA0;
ACP_API void (*GAM_fn_vAskToChangeLevel)( char *szLevelName, BYTE bSaveGame ) = 0x4054D0;
ACP_API HANDLE (*GAM_fn_hGetWindowHandle)( void ) = 0x401400;
