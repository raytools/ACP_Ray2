/****************************************************************************
 *
 * LOG - Spitfire's Log Module
 *
 ****************************************************************************/

#include "LOG.h"
#include "GAM/GAM.h"
#include "private/framework.h"


#define LOG_C_szFilePath "CPALog.txt"

static FILE *LOG_gs_hFile;
static CRITICAL_SECTION LOG_gs_stErrorOperation;

BOOL LOG_g_bIsInit = FALSE;


static void fn_vOpenFile( void )
{
	FILE *hFile = fopen(LOG_C_szFilePath, "w");
	LOG_gs_hFile = hFile;
}

static void fn_vCloseFile( void )
{
	if ( LOG_gs_hFile )
		fclose(LOG_gs_hFile);
	LOG_gs_hFile = NULL;
}

static void fn_vCloseApp( void )
{
	LOG_g_bIsInit = FALSE;
	fn_vCloseFile();
	DeleteCriticalSection(&LOG_gs_stErrorOperation);
	GAM_fn_vChangeEngineMode(E_EM_ModeStoppingProgram);
}

static size_t fn_ulBufSizeForFmt( char const *szFmt, va_list args )
{
	va_list argsUse;
	va_copy(argsUse, args);
	long lSize = vsnprintf(NULL, 0, szFmt, argsUse);
	return lSize + 1;
}

static size_t fn_ulBufSizeForFmtV( char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);
	long lSize = vsnprintf(NULL, 0, szFmt, args);
	va_end(args);
	return lSize + 1;
}

static void fn_vPrintWithHF( char const *szHeader, char const *szFooter, char const *szFmt, va_list args )
{
	if ( !LOG_gs_hFile )
		return;

	EnterCriticalSection(&LOG_gs_stErrorOperation);

	fputs(szHeader, LOG_gs_hFile);
	vfprintf(LOG_gs_hFile, szFmt, args);
	fputs(szFooter, LOG_gs_hFile);
	fflush(LOG_gs_hFile);

	LeaveCriticalSection(&LOG_gs_stErrorOperation);
}

static void fn_vPrintWithHFExtra(
	char const *szHeader,
	char const *szFooter,
	char const *szFile,
	unsigned long ulLine,
	char const *szFunction,
	char const *szFmt,
	va_list args )
{
	if ( !LOG_gs_hFile )
		return;

	EnterCriticalSection(&LOG_gs_stErrorOperation);

	fputs(szHeader, LOG_gs_hFile);
	if ( szFile )
		fprintf(LOG_gs_hFile, "'%s', line %u:\n\t", szFile, ulLine);
	if ( szFunction )
		fprintf(LOG_gs_hFile, "%s : ", szFunction);
	vfprintf(LOG_gs_hFile, szFmt, args);
	fputs(szFooter, LOG_gs_hFile);
	fflush(LOG_gs_hFile);

	LeaveCriticalSection(&LOG_gs_stErrorOperation);
}

static int fn_lMessageBox( char const *szFmt, va_list args, UINT uType )
{
	HANDLE hWnd = GAM_fn_hGetWindowHandle();
	size_t ulSize = fn_ulBufSizeForFmt(szFmt, args);
	char *szMsg = malloc(ulSize);
	if ( !szMsg )
		return IDABORT;

	vsnprintf(szMsg, ulSize, szFmt, args);
	int lResult = MessageBox((IsWindow(hWnd) ? hWnd : NULL), szMsg, "CPA Error", uType);

	free(szMsg);
	return lResult;
}

static int fn_lMessageBoxExtra( char const *szFmt, char const *szFile, unsigned long ulLine, char const *szFunction, va_list args, UINT uType )
{
	HANDLE hWnd = GAM_fn_hGetWindowHandle();
	size_t ulSize = fn_ulBufSizeForFmt(szFmt, args);
	size_t ulSizeExtra = fn_ulBufSizeForFmtV("'%s', line %u:\n%s : ", szFile, ulLine, szFunction);
	
	char *szMsg = malloc(ulSize + ulSizeExtra);
	char *szWritePtr = szMsg;
	if ( !szMsg )
		return IDABORT;

	if ( szFile )
		szWritePtr += sprintf(szWritePtr, "'%s', line %u:\n", szFile, ulLine);
	if ( szFunction )
		szWritePtr += sprintf(szWritePtr, "%s : ", szFunction);

	vsnprintf(szWritePtr, ulSize, szFmt, args);
	int lResult = MessageBox((IsWindow(hWnd) ? hWnd : NULL), szMsg, "CPA Error", uType);

	free(szMsg);
	return lResult;
}


void LOG_fn_vInit( void )
{
	if ( LOG_g_bIsInit )
		return;
	LOG_g_bIsInit = TRUE;

	fn_vOpenFile();
	InitializeCriticalSection(&LOG_gs_stErrorOperation);

	if ( !LOG_gs_hFile )
	{
		char szMsg[256];
		sprintf(szMsg, "%s : Could not open '%s'.\nLog entries will not be written during this session.", __func__, LOG_C_szFilePath);
		MessageBox(NULL, szMsg, "CPA Error", MB_OK | MB_ICONWARNING);
	}
}


void LOG_fn_vInfo( char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);
	fn_vPrintWithHF("[Info] ", "\n", szFmt, args);
	va_end(args);
}

void LOG_fn_vWarn( char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);
	fn_vPrintWithHF("[Warn] ", "\n", szFmt, args);
	va_end(args);
}

void LOG_fn_vError( char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);
	fn_vPrintWithHF("\n[ERROR] ", "\n\n", szFmt, args);
	va_end(args);
}

void LOG_fn_vErrorFatal( char const *szFmt, ... )
{
	va_list args, argsForDlg;
	va_start(args, szFmt);
	va_copy(argsForDlg, args);
	fn_vPrintWithHF("\n[ERROR] ", "\n\n", szFmt, args);
	fn_lMessageBox(szFmt, argsForDlg, MB_OK | MB_ICONERROR);
	va_end(args);
	fn_vCloseApp();
}


void LOG_fn_vInfoEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);
	fn_vPrintWithHFExtra("[Info] ", "\n", szFile, ulLine, szFunction, szFmt, args);
	va_end(args);
}

void LOG_fn_vWarnEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);
	fn_vPrintWithHFExtra("[Warn] ", "\n", szFile, ulLine, szFunction, szFmt, args);
	va_end(args);
}

void LOG_fn_vErrorEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);
	fn_vPrintWithHFExtra("\n[ERROR] ", "\n\n", szFile, ulLine, szFunction, szFmt, args);
	va_end(args);
}

void LOG_fn_vErrorFatalEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... )
{
	va_list args, argsForDlg;
	va_start(args, szFmt);
	va_copy(argsForDlg, args);
	fn_vPrintWithHFExtra("\n[ERROR] ", "\n\n", szFile, ulLine, szFunction, szFmt, args);
	fn_lMessageBoxExtra(szFmt, szFile, ulLine, szFunction, argsForDlg, MB_OK | MB_ICONERROR);
	va_end(args);
	fn_vCloseApp();
}
