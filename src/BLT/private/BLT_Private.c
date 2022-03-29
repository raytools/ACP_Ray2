/****************************************************************************
 *
 * Private functions for BLT module
 *
 ****************************************************************************/

#include "BLT_Private.h"
#include "GAM/GAM.h"
#include "private/framework.h"


BOOL g_bSuppressInfoWindow = FALSE;


FILE * BLT_fn_hOpenFileForWrite( char *szFilePath )
{
	FILE *hFile = fopen(szFilePath, "w");
	return hFile;
}

void BLT_fn_vCloseFile( FILE *hFile )
{
	fclose(hFile);
}

void BLT_fn_vPrintToFile( char *szText, FILE *hFile )
{
	if ( !hFile )
		return;

	fprintf(hFile, "%s", szText);
	fflush(hFile);
}

void BLT_fn_vPrintToInfoWindow( char *szText )
{
	if ( g_bSuppressInfoWindow )
		return;

	long lResult = MessageBox(
		GAM_fn_hGetWindowHandle(),
		szText,
		"CPA Information Window",
		MB_TOPMOST | MB_ICONEXCLAMATION | MB_OKCANCEL
	);

	if ( lResult == IDCANCEL )
		g_bSuppressInfoWindow = TRUE;
}
