#include "Loader.h"
#include "private/Config.h"
#include "private/Errlog.h"
#include "private/framework.h"


#define C_ulMaxSubmodules 128

// Note: all paths are relative to the application directory

char const C_szAcpDir[] = ".\\ACP";
char const C_szModDir[] = ".\\ACP\\Mods";
char const C_szModInfo[] = "ModInfo";

DWORD g_ulNbSubmodules = 0;
LDR_tdstSubmodule g_a_stSubmodules[C_ulMaxSubmodules] = { 0 };


BOOL LDR_fn_bLoadSubmodule( char const *szPath )
{
	char szErr[256];

	HMODULE hDll = LoadLibrary(szPath);
	if ( !hDll )
	{
		sprintf(szErr, "Cannot load submodule '%s'!", szPath);
		ERR_Error(szErr);
		return FALSE;
	}

	LDR_tdstSubmoduleInfo *p_stInfo = (LDR_tdstSubmoduleInfo *)GetProcAddress(hDll, C_szModInfo);
	if ( !p_stInfo )
	{
		sprintf(szErr, "Cannot load submodule '%s' - Submodule info invalid or not exported!", szPath);
		ERR_Error(szErr);
		return FALSE;
	}

	DWORD ulSubmoduleId = g_ulNbSubmodules++;
	LDR_tdstSubmodule *p_stSubmodule = &g_a_stSubmodules[ulSubmoduleId];
	p_stSubmodule->hDLl = hDll;
	p_stSubmodule->stInfo = *p_stInfo;

	sprintf(szErr, "Submodule '%s' loaded with id %u.", p_stSubmodule->stInfo.szName, ulSubmoduleId);
	ERR_Info(szErr);
	return TRUE;
}

BOOL LDR_fn_bInitSubmodule( DWORD ulSubmoduleId )
{
	char szErr[256];

	LDR_tdstSubmoduleInfo *p_stInfo = &g_a_stSubmodules[ulSubmoduleId].stInfo;
	LDR_tdfnInitProc p_fnInitProc = p_stInfo->p_fnInitProc;

	if ( !p_fnInitProc )
	{
		sprintf(
			szErr,
			"Failed to initialise submodule %u : '%s' - init procedure not set!",
			ulSubmoduleId, p_stInfo->szName
		);
		ERR_Error(szErr);
		return FALSE;
	}

	BOOL bResult = p_fnInitProc(ulSubmoduleId);

	if ( !bResult )
	{
		sprintf(
			szErr,
			"Submodule %u : '%s' was not initialised, check application log for details.",
			ulSubmoduleId, p_stInfo->szName
		);
		ERR_Error(szErr);
		return FALSE;
	}

	sprintf(szErr, "Submodule %u : '%s' initialised.", ulSubmoduleId, p_stInfo->szName);
	ERR_Info(szErr);
	return TRUE;
}

void LDR_fn_vLoadAllSubmodules( void )
{
	char szBuffer[MAX_PATH];

	for ( DWORD i = 0; i < g_ulNbLoadOrder; i++ )
	{
		char *szDllName = g_a_szLoadOrder[i];
		sprintf(szBuffer, "%s\\%s", C_szModDir, szDllName);

		LDR_fn_bLoadSubmodule(szBuffer);
	}

	char szErr[128];
	sprintf(szErr, "Loaded %u submodules.", g_ulNbSubmodules);
	ERR_Info(szErr);
}

void LDR_fn_vInitAllSubmodules( void )
{
	DWORD ulNbInit = 0;

	for ( DWORD i = 0; i < g_ulNbSubmodules; i++ )
	{
		BOOL bResult = LDR_fn_bInitSubmodule(i);
		ulNbInit += bResult;
	}

	char szErr[128];
	sprintf(szErr, "Initialised %u submodules.", ulNbInit);
	ERR_Info(szErr);
}

LDR_API void LDR_fn_vInit( void )
{
	ERR_fn_vInit();

	ERR_Info("Reading config file...");
	if ( !CFG_fn_bReadCfgFile() )
		return;

	ERR_Info("Loading submodules...");
	LDR_fn_vLoadAllSubmodules();

	ERR_Info("Initialising submodules...");
	LDR_fn_vInitAllSubmodules();

	// TODO: ERM reimplementation
}
