/****************************************************************************
 *
 * LOG - I/O functions
 *
 ****************************************************************************/

#include "LOG_IO.h"
#include "GAM/GAM.h"
#include "private/framework.h"


BOOL LOG_g_bSuppressInfoWindow = FALSE;


FILE * LOG_fn_hOpenFileForWrite( char *szFilePath )
{
	FILE *hFile = fopen(szFilePath, "w");
	return hFile;
}

void LOG_fn_vCloseFile( FILE *hFile )
{
	fclose(hFile);
}

void LOG_fn_vPrintToFile( char *szText, FILE *hFile )
{
	if ( !hFile )
		return;

	fprintf(hFile, "%s", szText);
	fflush(hFile);
}

void LOG_fn_vPrintToInfoWindow( char *szText )
{
	if ( LOG_g_bSuppressInfoWindow )
		return;

	long lResult = MessageBox(
		GAM_fn_hGetWindowHandle(),
		szText,
		"CPA Information Window",
		MB_TOPMOST | MB_ICONEXCLAMATION | MB_OKCANCEL
	);

	if ( lResult == IDCANCEL )
		LOG_g_bSuppressInfoWindow = TRUE;
}

BOOL LOG_fn_bAskForDebug( void )
{
	long lResult = MessageBox(
		GAM_fn_hGetWindowHandle(),
		"Do you want to debug?",
		"CPA Information Window",
		MB_TOPMOST | MB_ICONEXCLAMATION | MB_YESNO
	);

	return (lResult == IDYES);
}

void LOG_fn_vOutputErrorMsg( FILE *hFile, BOOL bInfoWindow, char const *szFormat, ... )
{
	va_list args;
	va_start(args, szFormat);

	long lSize = vsnprintf(NULL, 0, szFormat, args);
	char *szBuffer = _alloca(lSize + 1);

	va_end(args);
	va_start(args, szFormat);

	vsprintf(szBuffer, szFormat, args);

	LOG_fn_vPrintToFile(szBuffer, hFile);
	if ( bInfoWindow )
		LOG_fn_vPrintToInfoWindow(szBuffer);

	va_end(args);
}
