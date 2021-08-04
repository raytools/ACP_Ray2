#include "Loader.h"
#include "private/Ldr_Private.h"
#include "private/framework.h"


// Note: all paths are relative to the application directory

char const C_szAcpDir[] = ".\\ACP";
char const C_szModDir[] = ".\\ACP\\Mods";
char const C_szCfgFile[] = "loader.cfg";

DWORD g_ulNbMods = 0;
BYTE g_bReticulateSplines = 0; // reserved
BYTE g_bEnableErm = FALSE;


FILE * fn_hOpenCfgFileForReading( void )
{
	char szPath[MAX_PATH];
	sprintf(szPath, "%s\\%s", C_szAcpDir, C_szCfgFile);

	return fopen(szPath, "rb");
}


DWORD fn_ulReadNextDword( FILE *hFile )
{
	DWORD value;

	if ( fread(&value, sizeof(DWORD), 1, hFile) )
		return value;

	return 0;
}

BYTE fn_ucReadNextByte( FILE *hFile )
{
	BYTE value;

	if ( fread(&value, sizeof(BYTE), 1, hFile) )
		return value;

	return 0;
}

char * fn_szReadNextString( FILE *hFile )
{
	char szBuffer[MAX_STRING];
	BYTE nChars = fn_ucReadNextByte(hFile);

	if ( !nChars )
		return NULL;

	if ( fread(szBuffer, sizeof(char), nChars, hFile) != nChars )
		return NULL;

	char *szValue = malloc(nChars);
	if ( !szValue )
		return NULL;
	
	memcpy(szValue, szBuffer, nChars);
	return szValue;
}

void LDR_fn_vReadGeneralCfg( FILE *hFile )
{
	g_bReticulateSplines = fn_ucReadNextByte(hFile);
	g_bEnableErm = fn_ucReadNextByte(hFile);
}

void LDR_fn_vReadLoadOrder( FILE *hFile )
{
	char szBuffer[MAX_PATH];
	BYTE nMods = fn_ucReadNextByte(hFile);

	for ( BYTE i = 0; i < nMods; i++ )
	{
		// TODO write to array/list
	}

	g_ulNbMods = nMods;
}

BOOL LDR_fn_bReadCfgFile( void )
{
	FILE *hFile = fn_hOpenCfgFileForReading();
	if ( !hFile )
		return FALSE;

	if ( fn_ulReadNextDword(hFile) != C_ulMagicHeader )
		return FALSE;

	LDR_tdeCfgSection ulSection = fn_ucReadNextByte(hFile);
	switch ( ulSection )
	{
	case E_Cfg_General:
		LDR_fn_vReadGeneralCfg(hFile);
		break;

	case E_Cfg_LoadOrder:
		LDR_fn_vReadLoadOrder(hFile);
		break;
	}

	fclose(hFile);
	return TRUE;
}
