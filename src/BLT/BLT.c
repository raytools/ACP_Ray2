/****************************************************************************
 *
 * BLT - Spitfire's Better Log Tool
 *
 ****************************************************************************/

#include "BLT.h"
#include "private/BLT_Private.h"
#include "private/framework.h"


#define BLT_C_szBLTModuleVersion	"BLT V1.0.0"
#define BLT_C_szBLTModuleName		"Spitfire's Better Log Tool"
#define BLT_C_szBLTModuleDate		__DATE__

BOOL g_bIsBLTInit = FALSE;
BLT_tdxModuleId g_xBLTModuleId = 0;

CRITICAL_SECTION g_stCriticalSection = { 0 };

BLT_tdstModule *BLT_g_a_pstModuleTab[BLT_C_MaxModules] = { 0 };
BLT_tdxModuleId BLT_g_xNbOfModule = 0;

FILE *g_hLogFile = NULL;
BLT_tdstErrorInfo BLT_g_stLastErrorInfo = { 0 };

char *g_szErrBuffer[BLT_C_MaxErrBuffer] = { 0 };


/*
 * Module
 */

BLT_tdxModuleId BLT_fn_xRegisterModule( char const *szCodeVersion, char const *szFullName, char const *szDate )
{
	if ( !g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&g_stCriticalSection);

	if ( BLT_g_xNbOfModule >= BLT_C_MaxModules )
	{
		// TODO
		return;
	}

	BLT_tdxModuleId xModuleId = ++BLT_g_xNbOfModule;
	int lModuleTabIdx = BLT_M_lModuleTabIdxFromModuleId(xModuleId);

	BLT_tdstModule *pModule = calloc(1, sizeof(BLT_tdstModule));

	pModule->szCodeVersion = szCodeVersion;
	pModule->szFullName = szFullName;
	pModule->szDate = szDate;

	BLT_g_a_pstModuleTab[lModuleTabIdx] = pModule;

	LeaveCriticalSection(&g_stCriticalSection);
	return xModuleId;
}

void BLT_fn_vModuleUseErrorTab( BLT_tdxModuleId xModuleId, char **d_szErrorMsg, unsigned long ulNbError,
								unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation )
{
	EnterCriticalSection(&g_stCriticalSection);

	if ( !BLT_M_bIsValidModuleId(xModuleId) )
	{
		// TODO
		return;
	}

	BLT_tdstModule *pModule = BLT_M_pstGetModuleById(xModuleId);
	BLT_tdstErrorTab *pTab = calloc(1, sizeof(BLT_tdstErrorTab));

	pTab->d_szErrorMsg = d_szErrorMsg;
	pTab->ulNbError = ulNbError;
	pTab->uwIdStartOfWarning = uwIdStartOfWarning;
	pTab->uwIdStartOfInformation = uwIdStartOfInformation;

	pModule->p_stErrorTab = pTab;

	LeaveCriticalSection(&g_stCriticalSection);
}


/*
 * Error
 */

void BLT_fn_vError(
	char *szMsg,
	BLT_tdeErrorType eType,
	BLT_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine )
{
	EnterCriticalSection(&g_stCriticalSection);

	// TODO

	LeaveCriticalSection(&g_stCriticalSection);
}


void BLT_fn_vErrorFromId(
	unsigned short uwErrorId,
	BLT_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szExtraMsg )
{
	EnterCriticalSection(&g_stCriticalSection);

	BLT_tdstModule *pModule = BLT_M_pstGetModuleById(xModuleId);
	BLT_tdstErrorTab *pTab = pModule->p_stErrorTab;

	if ( !pTab )
	{
		// TODO
		LeaveCriticalSection(&g_stCriticalSection);
		return;
	}

	if ( uwErrorId >= pTab->ulNbError )
	{
		// TODO
		LeaveCriticalSection(&g_stCriticalSection);
		return;
	}

	BLT_tdeErrorType eType = uwErrorId > pTab->uwIdStartOfWarning
		? (uwErrorId > pTab->uwIdStartOfInformation ? BLT_E_Information : BLT_E_Warning)
		: BLT_E_Fatal;

	// TODO

	LeaveCriticalSection(&g_stCriticalSection);
}

void BLT_fn_vInit( void )
{
	if ( g_bIsBLTInit )
		return;
	g_bIsBLTInit = TRUE;

	InitializeCriticalSection(&g_stCriticalSection);
	g_hLogFile = BLT_fn_hOpenFileForWrite(BLT_C_szLogFileName);
	g_xBLTModuleId = BLT_fn_xRegisterModule(BLT_C_szBLTModuleVersion, BLT_C_szBLTModuleName, BLT_C_szBLTModuleDate);
}
