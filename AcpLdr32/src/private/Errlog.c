#include "Errlog.h"
#include "../Loader.h"
#include "framework.h"


#define C_MaxError 512u
#define C_szSeparator "======================================================================"


char const C_szLogFileName[] = "LdrError.log";

char g_szLogPath[MAX_PATH] = { 0 };
BOOL g_bErrInit = FALSE;

char g_szBuffer[C_MaxError] = { 0 };


void ERR_fn_vPrintToLog( char const *szMsg )
{
	FILE *hFile = fopen(g_szLogPath, "a");
	if ( hFile )
	{
		fprintf(hFile, "%s\n", szMsg);
		fclose(hFile);
	}
}

void ERR_fn_vPrintError( char const *szMsg, char const *szFunc, short wLineNum, char const *szFile )
{
	if ( !g_bErrInit )
		return;

	sprintf(
		g_szBuffer,
		"Error in file '%s', line %d:\n"
		"-> %s : %s",
		szFile, wLineNum, szFunc, szMsg
	);

	ERR_fn_vPrintToLog(C_szSeparator);
	ERR_fn_vPrintToLog(g_szBuffer);
	ERR_fn_vPrintToLog(C_szSeparator "\n");
}

void ERR_fn_vPrintWarning( char const *szMsg, char const *szFunc, short wLineNum, char const *szFile )
{
	if ( !g_bErrInit ) return;

	sprintf(
		g_szBuffer,
		"Warning in file '%s', line %d:\n"
		"-> %s : %s\n",
		szFile, wLineNum, szFunc, szMsg
	);
	
	ERR_fn_vPrintToLog(g_szBuffer);
}

void ERR_fn_vPrintInfo( char const *szMsg, char const *szFunc )
{
	if ( !g_bErrInit ) return;

	sprintf(
		g_szBuffer,
		"Just for information:\n"
		"-> %s : %s\n",
		szFunc, szMsg
	);
	
	ERR_fn_vPrintToLog(g_szBuffer);
}

void ERR_fn_vInit( void )
{
	sprintf(g_szLogPath, "%s\\%s", C_szAcpDir, C_szLogFileName);

	FILE *hFile = fopen(g_szLogPath, "w");
	if ( hFile )
	{
		fclose(hFile);
		g_bErrInit = TRUE;
	}
}
