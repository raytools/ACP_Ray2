/****************************************************************************
 *
 * BLT - Spitfire's Better Log Tool
 *
 ****************************************************************************/

#define BLT_USE_MODULE

#include "BLT.h"
#include "private/BLT_IO.h"
#include "private/BLT_Modules.h"
#include "private/framework.h"


#define BLT_C_szBLTModuleVersion	"BLT V1.0.0"
#define BLT_C_szBLTModuleName		"Spitfire's Better Log Tool"
#define BLT_C_szBLTModuleDate		__DATE__


CRITICAL_SECTION g_stErrorOperation = { 0 };
BOOL g_bIsBLTInit = FALSE;
BLT_tdxModuleId g_xBLTModuleId = 0;

BLT_tdstModule *BLT_g_a_pstModuleTab[BLT_C_MaxModules] = { 0 };
BLT_tdxModuleId BLT_g_xNbOfModule = 0;

FILE *g_hLogFile = NULL;
BLT_tdstErrorInfo BLT_g_stLastErrorInfo = { 0 };


void BLT_fn_vInit( void )
{
	if ( g_bIsBLTInit )
		return;
	g_bIsBLTInit = TRUE;

	InitializeCriticalSection(&g_stErrorOperation);
	g_hLogFile = BLT_fn_hOpenFileForWrite(BLT_C_szLogFileName);
	g_xBLTModuleId = BLT_fn_xRegisterModule(BLT_C_szBLTModuleVersion, BLT_C_szBLTModuleName, BLT_C_szBLTModuleDate);
}

/*
 * Module
 */

BLT_tdxModuleId BLT_fn_xRegisterModule( char const *szCodeAndVersion, char const *szFullName, char const *szDate )
{
	if ( !g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&g_stErrorOperation);

	if ( BLT_g_xNbOfModule >= BLT_C_MaxModules )
	{
		// TODO
		LeaveCriticalSection(&g_stErrorOperation);
		return 0;
	}

	BLT_tdxModuleId xModuleId = ++BLT_g_xNbOfModule;
	int lModuleTabIdx = BLT_M_lModuleTabIdxFromModuleId(xModuleId);

	BLT_tdstModule *pModule = calloc(1, sizeof(BLT_tdstModule));

	if ( !pModule )
	{
		// TODO
		LeaveCriticalSection(&g_stErrorOperation);
		return 0;
	}

	pModule->szCodeVersion = szCodeAndVersion;
	pModule->szFullName = szFullName;
	pModule->szDate = szDate;

	BLT_g_a_pstModuleTab[lModuleTabIdx] = pModule;

	LeaveCriticalSection(&g_stErrorOperation);
	return xModuleId;
}

void BLT_fn_vModuleUseErrorTab( BLT_tdxModuleId xModuleId, char **d_szErrorMsg, unsigned long ulNbError,
								unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation )
{
	if ( !g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&g_stErrorOperation);

	if ( !BLT_M_bModuleExists(xModuleId) )
	{
		// TODO
		LeaveCriticalSection(&g_stErrorOperation);
		return;
	}

	BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(xModuleId);
	BLT_tdstErrorTab *p_stTab = calloc(1, sizeof(BLT_tdstErrorTab));

	if ( !p_stTab )
	{
		// TODO
		LeaveCriticalSection(&g_stErrorOperation);
		return;
	}

	p_stTab->d_szErrorMsg = d_szErrorMsg;
	p_stTab->ulNbError = ulNbError;
	p_stTab->uwIdStartOfWarning = uwIdStartOfWarning;
	p_stTab->uwIdStartOfInformation = uwIdStartOfInformation;

	p_stModule->p_stErrorTab = p_stTab;

	LeaveCriticalSection(&g_stErrorOperation);
}


/*
 * Error
 */


void BLT_fn_vPrintLastError( char *szExtraMsg )
{
	char *szErrHeader;

	if ( !szExtraMsg )
		szExtraMsg = "";

	if ( BLT_g_stLastErrorInfo.eType == BLT_E_Information )
	{
		szErrHeader = "Just for information:";

		if ( BLT_g_stLastErrorInfo.xModuleId == BLT_C_DefaultModule )
		{
			BLT_fn_vOutputErrorMsg(
				g_hLogFile, FALSE,
				"%s\nIn file '%s', line %d:\n\t->\t%s\n\t\t%s\n",
				szErrHeader,
				BLT_g_stLastErrorInfo.szFileName, BLT_g_stLastErrorInfo.uwLineNum,
				BLT_g_stLastErrorInfo.szErrorMsg,
				szExtraMsg
			);
		}
		else
		{
			BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(BLT_g_stLastErrorInfo.xModuleId);

			BLT_fn_vOutputErrorMsg(
				g_hLogFile, FALSE,
				"%s\nFrom %s: '%s' of %s, in file '%s', line %d:\n\t->\t%s\n\t\t%s\n",
				szErrHeader,
				p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
				BLT_g_stLastErrorInfo.szFileName, BLT_g_stLastErrorInfo.uwLineNum,
				BLT_g_stLastErrorInfo.szErrorMsg,
				szExtraMsg
			);
		}

		return;
	}

	BLT_fn_vPrintToFile("\n================================================================================\n", g_hLogFile);

	switch ( BLT_g_stLastErrorInfo.eType )
	{
	case BLT_E_Fatal:
		szErrHeader = "Fatal Error:";
		break;

	case BLT_E_Warning:
		szErrHeader = "Warning Error:";
		break;

	default:
		szErrHeader = "Unknown Error:";
		break;
	}

	if ( BLT_g_stLastErrorInfo.xModuleId == BLT_C_DefaultModule )
	{
		BLT_fn_vOutputErrorMsg(
			g_hLogFile, TRUE,
			"%s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			BLT_g_stLastErrorInfo.szFileName, BLT_g_stLastErrorInfo.uwLineNum,
			BLT_g_stLastErrorInfo.szErrorMsg,
			szExtraMsg
		);
	}
	else
	{
		BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(BLT_g_stLastErrorInfo.xModuleId);

		BLT_fn_vOutputErrorMsg(
			g_hLogFile, TRUE,
			"%s\nFrom %s: '%s' of %s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
			BLT_g_stLastErrorInfo.szFileName, BLT_g_stLastErrorInfo.uwLineNum,
			BLT_g_stLastErrorInfo.szErrorMsg,
			szExtraMsg
		);
	}

	BLT_fn_vPrintToFile("================================================================================\n\n", g_hLogFile);
}

BLT_tdstErrorInfo * BLT_fn_p_stGetLastError( BLT_tdxModuleId xModuleId )
{
	BLT_tdstErrorInfo *p_stInfo = BLT_M_bModuleExists(xModuleId)
		? &BLT_M_pstGetModuleById(xModuleId)->stLastErrorForModule
		: &BLT_g_stLastErrorInfo;

	return p_stInfo;
}

void BLT_fn_vError(
	BLT_tdeErrorType eType,
	BLT_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szMsg,
	char *szExtraMsg )
{
	if ( !g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&g_stErrorOperation);

	BLT_tdstErrorInfo stInfo = { 0 };

	if ( strlen(szMsg) >= BLT_C_MaxErrorMsg )
	{
		// TODO
	}

	strncpy(stInfo.szErrorMsg, szMsg, BLT_C_MaxErrorMsg - 1);
	stInfo.eType = eType;
	stInfo.xModuleId = BLT_C_DefaultModule;
	stInfo.szFileName = szInFile;
	stInfo.uwLineNum = uwAtLine;

	if ( BLT_M_bModuleExists(xModuleId) )
	{
		// TODO
		stInfo.xModuleId = xModuleId;
		BLT_M_pstGetModuleById(xModuleId)->stLastErrorForModule = stInfo;
	}
	BLT_g_stLastErrorInfo = stInfo;

	BLT_fn_vPrintLastError(szExtraMsg);

	LeaveCriticalSection(&g_stErrorOperation);
}


void BLT_fn_vErrorFromId(
	unsigned short uwErrorId,
	BLT_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szExtraMsg )
{
	if ( !g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&g_stErrorOperation);

	if ( !BLT_M_bModuleExists(xModuleId) )
	{
		// TODO
		LeaveCriticalSection(&g_stErrorOperation);
		return;
	}

	BLT_tdstErrorInfo stInfo = { 0 };

	BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(xModuleId);
	BLT_tdstErrorTab *p_stTab = p_stModule->p_stErrorTab;

	if ( !p_stTab )
	{
		// TODO
		LeaveCriticalSection(&g_stErrorOperation);
		return;
	}

	if ( uwErrorId >= p_stTab->ulNbError )
	{
		// TODO
		LeaveCriticalSection(&g_stErrorOperation);
		return;
	}

	BLT_tdeErrorType eType = uwErrorId > p_stTab->uwIdStartOfWarning
		? (uwErrorId > p_stTab->uwIdStartOfInformation ? BLT_E_Information : BLT_E_Warning)
		: BLT_E_Fatal;

	if ( strlen(p_stTab->d_szErrorMsg[uwErrorId]) >= BLT_C_MaxErrorMsg )
	{
		// TODO
	}

	strncpy(stInfo.szErrorMsg, p_stTab->d_szErrorMsg[uwErrorId], BLT_C_MaxErrorMsg - 1);
	stInfo.eType = eType;
	stInfo.uwErrorId = uwErrorId;
	stInfo.xModuleId = xModuleId;
	stInfo.szFileName = szInFile;
	stInfo.uwLineNum = uwAtLine;

	p_stModule->stLastErrorForModule = stInfo;
	BLT_g_stLastErrorInfo = stInfo;

	BLT_fn_vPrintLastError(szExtraMsg);

	LeaveCriticalSection(&g_stErrorOperation);
}
