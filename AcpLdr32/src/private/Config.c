#include "Config.h"
#include "Errlog.h"
#include "../Loader.h"
#include "framework.h"


char const C_szCfgFile[] = "Loader.cfg";

BYTE g_bEnableErm = FALSE;
BYTE g_bReticulateSplines = 0; // reserved
DWORD g_ulNbLoadOrder = 0;
char **g_a_szLoadOrder = NULL;


FILE * CFG_fn_hOpenCfgFileForReading( void )
{
	char szPath[MAX_PATH];
	sprintf(szPath, "%s\\%s", C_szAcpDir, C_szCfgFile);

	return fopen(szPath, "rb");
}

DWORD CFG_fn_ulReadNextDword( FILE *hFile )
{
	DWORD value;

	if ( fread(&value, sizeof(DWORD), 1, hFile) )
		return value;

	ERR_Error("Error reading dword from config file");
	return 0;
}

BYTE CFG_fn_ucReadNextByte( FILE *hFile )
{
	BYTE value;

	if ( fread(&value, sizeof(BYTE), 1, hFile) )
		return value;

	ERR_Error("Error reading byte from config file");
	return 0;
}

char * CFG_fn_szReadNextString( FILE *hFile )
{
	char szBuffer[C_ulMaxString];
	BYTE nChars = CFG_fn_ucReadNextByte(hFile);

	if ( nChars == 0 || nChars > C_ulMaxString )
	{
		ERR_Error("Incorrect string length declared in config file");
		return NULL;
	}

	if ( fread(szBuffer, sizeof(char), nChars, hFile) != nChars )
	{
		ERR_Warning("String is shorter than its declared length");
	}

	char *szValue = malloc(nChars);
	if ( !szValue )
	{
		ERR_Error("Cannot allocate memory for string");
		return NULL;
	}

	memcpy(szValue, szBuffer, nChars);
	return szValue;
}

void CFG_fn_vReadGeneralCfg( FILE *hFile )
{
	g_bReticulateSplines = CFG_fn_ucReadNextByte(hFile);
	g_bEnableErm = CFG_fn_ucReadNextByte(hFile);
}

void CFG_fn_vReadLoadOrder( FILE *hFile )
{
	BYTE nMods = CFG_fn_ucReadNextByte(hFile);
	if ( nMods <= 0 )
	{
		ERR_Warning("No mods defined in the config file");
		return;
	}

	g_a_szLoadOrder = calloc(nMods, sizeof(char *));
	if ( !g_a_szLoadOrder )
	{
		ERR_Error("Cannot allocate memory for load order array");
		return;
	}

	for ( BYTE i = 0; i < nMods; i++ )
	{
		g_a_szLoadOrder[i] = CFG_fn_szReadNextString(hFile);
	}

	g_ulNbLoadOrder = nMods;
}

BOOL CFG_fn_bReadCfgFile( void )
{
	FILE *hFile = CFG_fn_hOpenCfgFileForReading();
	if ( !hFile )
	{
		ERR_Error("Cannot open config file");
		return FALSE;
	}

	if ( CFG_fn_ulReadNextDword(hFile) != C_ulMagicHeader )
	{
		ERR_Error("Incorrect format of config file");
		return FALSE;
	}

	LDR_tdeCfgSection ulSection;
	do
	{
		ulSection = CFG_fn_ucReadNextByte(hFile);

		switch ( ulSection )
		{
		case E_Cfg_General:
			CFG_fn_vReadGeneralCfg(hFile);
			break;

		case E_Cfg_LoadOrder:
			CFG_fn_vReadLoadOrder(hFile);
			break;

		case E_Cfg_End:
			break;
		}
	}
	while ( ulSection );

	fclose(hFile);
	return TRUE;
}
