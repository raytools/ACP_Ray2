#include "ACP_API.h"
#include "GAM.h"


///////////////////////
//
// GAM - Game Library
// 
///////////////////////


ACP_API BYTE (*GAM_fn_ucGetEngineMode)( void ) = 0x404C60;
ACP_API void (*GAM_fn_vChangeEngineMode)( BYTE ucMode ) = 0x404BF0;
ACP_API char * (*GAM_fn_p_szGetLevelName)( void ) = 0x404DA0;
ACP_API void (*GAM_fn_vAskToChangeLevel)( char szLevelName, BYTE bSaveGame ) = 0x4054D0;
