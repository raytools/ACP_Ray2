/****************************************************************************
 *
 * BLT - Spitfire's Better Log Tool
 *
 ****************************************************************************/

#include "BLT.h"
#include "private/BLT_IO.h"
#include "private/BLT_Modules.h"
#include "private/framework.h"


/****************************************************************************
 * BLT module info
 ****************************************************************************/
#define BLT_C_szBLTModuleVersion	"BLT V1.0.0"
#define BLT_C_szBLTModuleName		"Spitfire's Better Log Tool"
#define BLT_C_szBLTModuleDate		"Mar 30 2022"

/****************************************************************************
 * Private error tab for BLT
 ****************************************************************************/
#define M_DefineError(name, msg) name,
enum BCF_tdeBCFErrTab
{
	#include "private/BLT_Err.h"
	BLT_NbErr
};

#define M_DefineError(name, msg) msg,
char *g_a_szBLTErrTab[BLT_NbErr] =
{
	#include "private/BLT_Err.h"
};
/****************************************************************************/


CRITICAL_SECTION BLT_g_stErrorOperation = { 0 };

BOOL BLT_g_bIsBLTInit = FALSE;

BLT_tdstModule *BLT_g_a_pstModuleTab[BLT_C_MaxModules] = { 0 };
BLT_tdxModuleId BLT_g_xNbOfModule = 0;

BLT_tdstErrorInfo BLT_g_stLastErrorInfo = { 0 };
FILE *BLT_g_hLogFile = NULL;

BLT_tdxModuleId g_xBLTModuleId = 0;


/****************************************************************************
 * Init function
 ****************************************************************************/

void BLT_fn_vInit( void )
{
	if ( BLT_g_bIsBLTInit )
		return;
	BLT_g_bIsBLTInit = TRUE;

	InitializeCriticalSection(&BLT_g_stErrorOperation);
	BLT_g_hLogFile = BLT_fn_hOpenFileForWrite(BLT_C_szLogFileName);
	g_xBLTModuleId = BLT_fn_xRegisterModule(BLT_C_szBLTModuleVersion, BLT_C_szBLTModuleName, BLT_C_szBLTModuleDate);
	BLT_fn_vModuleUseErrorTab(g_xBLTModuleId, g_a_szBLTErrTab, BLT_NbErr, BLT_E_StartOfWarning, BLT_E_StartOfInfo);
}


/****************************************************************************
 * Module management
 ****************************************************************************/

BLT_tdxModuleId BLT_fn_xRegisterModule( char const *szCodeAndVersion, char const *szFullName, char const *szDate )
{
	if ( !BLT_g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&BLT_g_stErrorOperation);

	if ( BLT_g_xNbOfModule >= BLT_C_MaxModules )
	{
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_TooManyModules);
		LeaveCriticalSection(&BLT_g_stErrorOperation);
		return 0;
	}

	BLT_tdxModuleId xModuleId = ++BLT_g_xNbOfModule;
	int lModuleTabIdx = BLT_M_lModuleTabIdxFromModuleId(xModuleId);

	BLT_tdstModule *pModule = calloc(1, sizeof(BLT_tdstModule));

	if ( !pModule )
	{
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_AllocError);
		LeaveCriticalSection(&BLT_g_stErrorOperation);
		return 0;
	}

	pModule->szCodeVersion = szCodeAndVersion;
	pModule->szFullName = szFullName;
	pModule->szDate = szDate;

	BLT_g_a_pstModuleTab[lModuleTabIdx] = pModule;

	char szBuffer[256];
	sprintf(szBuffer, "The module [%s : '%s' of %s] is initialized with the id #%d",
				pModule->szCodeVersion, pModule->szFullName, pModule->szDate, xModuleId);

	if ( g_xBLTModuleId )
		BLT_M_vLogInfoEx(g_xBLTModuleId, szBuffer, NULL);
	else
		BLT_M_vLogInfo(szBuffer);

	LeaveCriticalSection(&BLT_g_stErrorOperation);
	return xModuleId;
}

void BLT_fn_vModuleUseErrorTab( BLT_tdxModuleId xModuleId, char **d_szErrorMsg, unsigned long ulNbError,
								unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation )
{
	if ( !BLT_g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&BLT_g_stErrorOperation);

	if ( !BLT_M_bModuleExists(xModuleId) )
	{
		char szBuffer[32];
		sprintf(szBuffer, "Module id #%d", xModuleId);
		BLT_M_vLogIdEx(g_xBLTModuleId, BLT_Err_ModuleNotExist, szBuffer);

		LeaveCriticalSection(&BLT_g_stErrorOperation);
		return;
	}

	BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(xModuleId);
	BLT_tdstErrorTab *p_stTab = calloc(1, sizeof(BLT_tdstErrorTab));

	if ( !p_stTab )
	{
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_AllocError);
		LeaveCriticalSection(&BLT_g_stErrorOperation);
		return;
	}

	p_stTab->d_szErrorMsg = d_szErrorMsg;
	p_stTab->ulNbError = ulNbError;
	p_stTab->uwIdStartOfWarning = uwIdStartOfWarning;
	p_stTab->uwIdStartOfInformation = uwIdStartOfInformation;

	p_stModule->p_stErrorTab = p_stTab;

	LeaveCriticalSection(&BLT_g_stErrorOperation);
}


/****************************************************************************
 * Error management
 ****************************************************************************/

void BLT_fn_vUpdateLastError( BLT_tdstErrorInfo *p_stError, char *szExtraMsg )
{
	char *szErrHeader;

	if ( !szExtraMsg )
		szExtraMsg = "";

	if ( p_stError->eType == BLT_E_Information )
	{
		szErrHeader = "Just for information:";

		if ( p_stError->xModuleId == BLT_C_DefaultModule )
		{
			BLT_fn_vOutputErrorMsg(
				BLT_g_hLogFile, FALSE,
				"%s\nIn file '%s', line %d:\n    ->  %s\n        %s\n",
				szErrHeader,
				p_stError->szFileName, p_stError->uwLineNum,
				p_stError->szErrorMsg,
				szExtraMsg
			);
		}
		else
		{
			BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(p_stError->xModuleId);

			BLT_fn_vOutputErrorMsg(
				BLT_g_hLogFile, FALSE,
				"%s\nFrom %s: '%s' of %s, in file '%s', line %d:\n    ->  %s\n        %s\n",
				szErrHeader,
				p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
				p_stError->szFileName, p_stError->uwLineNum,
				p_stError->szErrorMsg,
				szExtraMsg
			);
		}

		BLT_g_stLastErrorInfo = *p_stError;
		return;
	}

	BLT_fn_vPrintToFile("\n================================================================================\n",
						BLT_g_hLogFile);

	switch ( p_stError->eType )
	{
	case BLT_E_Fatal:
		BLT_g_bSuppressInfoWindow = FALSE;
		szErrHeader = "Fatal Error:";
		break;

	case BLT_E_Warning:
		szErrHeader = "Warning Error:";
		break;

	default:
		szErrHeader = "Unknown Error:";
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_UnknownErrType);
		break;
	}

	if ( p_stError->xModuleId == BLT_C_DefaultModule )
	{
		BLT_fn_vOutputErrorMsg(
			BLT_g_hLogFile, TRUE,
			"%s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			p_stError->szFileName, p_stError->uwLineNum,
			p_stError->szErrorMsg,
			szExtraMsg
		);
	}
	else
	{
		BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(p_stError->xModuleId);

		BLT_fn_vOutputErrorMsg(
			BLT_g_hLogFile, TRUE,
			"%s\nFrom %s: '%s' of %s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
			p_stError->szFileName, p_stError->uwLineNum,
			p_stError->szErrorMsg,
			szExtraMsg
		);
	}

	BLT_fn_vPrintToFile("================================================================================\n\n",
						BLT_g_hLogFile);

	BLT_g_stLastErrorInfo = *p_stError;

	/* If error is fatal, we are about to crash */
	if ( p_stError->eType == BLT_E_Fatal )
	{
		if ( BLT_fn_bAskForDebug() )
			DebugBreak();

		BLT_fn_vCloseApp();
	}
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
	if ( !BLT_g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&BLT_g_stErrorOperation);

	BLT_tdstErrorInfo stError = { 0 };

	if ( strlen(szMsg) >= BLT_C_MaxErrorMsg )
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_MsgTooLong);

	strncpy(stError.szErrorMsg, szMsg, BLT_C_MaxErrorMsg - 1);
	stError.eType = eType;
	stError.xModuleId = BLT_C_DefaultModule;
	stError.szFileName = szInFile;
	stError.uwLineNum = uwAtLine;

	if ( BLT_M_bModuleExists(xModuleId) )
	{
		stError.xModuleId = xModuleId;
		BLT_M_pstGetModuleById(xModuleId)->stLastErrorForModule = stError;
	}

	BLT_fn_vUpdateLastError(&stError, szExtraMsg);

	LeaveCriticalSection(&BLT_g_stErrorOperation);
}

void BLT_fn_vErrorFromId(
	unsigned short uwErrorId,
	BLT_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szExtraMsg )
{
	if ( !BLT_g_bIsBLTInit )
		BLT_fn_vInit();

	EnterCriticalSection(&BLT_g_stErrorOperation);

	if ( !BLT_M_bModuleExists(xModuleId) )
	{
		char szBuffer[32];
		sprintf(szBuffer, "Module id #%d", xModuleId);
		BLT_M_vLogIdEx(g_xBLTModuleId, BLT_Err_ModuleNotExist, szBuffer);

		LeaveCriticalSection(&BLT_g_stErrorOperation);
		return;
	}

	BLT_tdstErrorInfo stError = { 0 };

	BLT_tdstModule *p_stModule = BLT_M_pstGetModuleById(xModuleId);
	BLT_tdstErrorTab *p_stTab = p_stModule->p_stErrorTab;

	if ( !p_stTab )
	{
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_NoErrTab);
		LeaveCriticalSection(&BLT_g_stErrorOperation);
		return;
	}

	if ( uwErrorId >= p_stTab->ulNbError )
	{
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_NoErrTab);
		LeaveCriticalSection(&BLT_g_stErrorOperation);
		return;
	}

	BLT_tdeErrorType eType = uwErrorId > p_stTab->uwIdStartOfWarning
		? (uwErrorId > p_stTab->uwIdStartOfInformation ? BLT_E_Information : BLT_E_Warning)
		: BLT_E_Fatal;

	if ( strlen(p_stTab->d_szErrorMsg[uwErrorId]) >= BLT_C_MaxErrorMsg )
		BLT_M_vLogId(g_xBLTModuleId, BLT_Err_MsgTooLong);

	strncpy(stError.szErrorMsg, p_stTab->d_szErrorMsg[uwErrorId], BLT_C_MaxErrorMsg - 1);
	stError.eType = eType;
	stError.uwErrorId = uwErrorId;
	stError.xModuleId = xModuleId;
	stError.szFileName = szInFile;
	stError.uwLineNum = uwAtLine;

	p_stModule->stLastErrorForModule = stError;

	BLT_fn_vUpdateLastError(&stError, szExtraMsg);

	LeaveCriticalSection(&BLT_g_stErrorOperation);
}
