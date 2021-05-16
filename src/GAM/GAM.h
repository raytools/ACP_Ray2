#pragma once

#include <MTH.h>
#include <apidef.h>


///////////////////////
//
// GAM - Game Library
// 
///////////////////////


typedef enum GAM_tdeEngineMode
{
	e_EM_Preload = 1,
	e_EM_Shutdown = 2,
	e_EM_FilesLoaded = 3,
	// state 4?
	e_EM_LoadingScreen = 5,
	e_EM_ChangeLevel = 6,
	e_EM_DesinitDeathLoop = 7,
	e_EM_SnifThePlayerIsDead = 8,
	e_EM_Play = 9
} GAM_tdeEngineMode;


ACP_API extern BYTE (*GAM_fn_ucGetEngineMode)( void );
ACP_API extern void (*GAM_fn_vChangeEngineMode)( BYTE ucMode );
ACP_API extern char * (*GAM_fn_p_szGetLevelName)( void );
ACP_API extern void (*GAM_fn_vAskToChangeLevel)( char szLevelName, BYTE bSaveGame );
