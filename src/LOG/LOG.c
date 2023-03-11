/****************************************************************************
 *
 * LOG - Spitfire's Log & Error Module
 *
 ****************************************************************************/

/* LOG is a module in itself */
#define LOG_USE_MODULE

#include "LOG.h"
#include "private/LOG_IO.h"
#include "private/LOG_Modules.h"
#include "GAM/GAM.h"
#include "private/framework.h"


/****************************************************************************
 * LOG module info
 ****************************************************************************/
#define LOG_C_szLOGModuleVersion	"LOG V1.1.0"
#define LOG_C_szLOGModuleName		"Spitfire's Log & Error Module"
#define LOG_C_szLOGModuleDate		"Mar 11 2023"

/****************************************************************************
 * Private error tab for LOG
 ****************************************************************************/
enum LOG_tdeLOGErrTab
{
	#define M_DefineError(name, msg) name,
	#include "private/LOG_Err.h"
	LOG_NbErr
};

char *g_a_szLOGErrTab[LOG_NbErr] =
{
	#define M_DefineError(name, msg) msg,
	#include "private/LOG_Err.h"
};
/****************************************************************************/


CRITICAL_SECTION LOG_g_stErrorOperation = { 0 };

BOOL LOG_g_bIsLOGInit = FALSE;

LOG_tdstModule *LOG_g_a_pstModuleTab[LOG_C_MaxModules] = { 0 };
LOG_tdxModuleId LOG_g_xNbOfModule = 0;

LOG_tdstErrorInfo LOG_g_stLastErrorInfo = { 0 };
FILE *LOG_g_hLogFile = NULL;

LOG_tdxModuleId g_xLOGModuleId = LOG_C_DefaultModule;


/****************************************************************************
 * Init function
 ****************************************************************************/

void LOG_fn_vInit( void )
{
	if ( LOG_g_bIsLOGInit )
		return;
	LOG_g_bIsLOGInit = TRUE;

	InitializeCriticalSection(&LOG_g_stErrorOperation);
	LOG_g_hLogFile = LOG_fn_hOpenFileForWrite(LOG_C_szLogFileName);
	g_xLOGModuleId = LOG_fn_xRegisterModule(LOG_C_szLOGModuleVersion, LOG_C_szLOGModuleName, LOG_C_szLOGModuleDate);
	LOG_fn_vModuleUseErrorTab(g_xLOGModuleId, g_a_szLOGErrTab, LOG_NbErr, LOG_E_StartOfWarning, LOG_E_StartOfInfo);
}

void LOG_fn_vCloseApp( void )
{
	LOG_fn_vCloseFile(LOG_g_hLogFile);
	GAM_fn_vChangeEngineMode(E_EM_ModeStoppingProgram);
}


/****************************************************************************
 * Module management
 ****************************************************************************/

LOG_tdxModuleId LOG_fn_xRegisterModule( char const *szCodeAndVersion, char const *szFullName, char const *szDate )
{
	if ( !LOG_g_bIsLOGInit )
		LOG_fn_vInit();

	EnterCriticalSection(&LOG_g_stErrorOperation);

	if ( LOG_g_xNbOfModule >= LOG_C_MaxModules )
	{
		LOG_M_vLogId(g_xLOGModuleId, LOG_Err_TooManyModules);
		LeaveCriticalSection(&LOG_g_stErrorOperation);
		return LOG_C_DefaultModule;
	}

	LOG_tdxModuleId xModuleId = LOG_g_xNbOfModule++;

	LOG_tdstModule *pModule = calloc(1, sizeof(LOG_tdstModule));

	if ( !pModule )
	{
		LOG_M_vLogId(g_xLOGModuleId, LOG_Err_AllocError);
		LeaveCriticalSection(&LOG_g_stErrorOperation);
		return LOG_C_DefaultModule;
	}

	pModule->szCodeVersion = szCodeAndVersion;
	pModule->szFullName = szFullName;
	pModule->szDate = szDate;

	LOG_M_pstGetModuleById(xModuleId) = pModule;

	char szBuffer[256];
	sprintf(szBuffer, "The module [%s : '%s' of %s] is initialized with the id #%d",
				pModule->szCodeVersion, pModule->szFullName, pModule->szDate, xModuleId);

	LOG_M_vLogInfo(LOG_C_DefaultModule, szBuffer);

	LeaveCriticalSection(&LOG_g_stErrorOperation);
	return xModuleId;
}

void LOG_fn_vModuleUseErrorTab( LOG_tdxModuleId xModuleId, char **d_szErrorMsg, unsigned long ulNbError,
								unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation )
{
	if ( !LOG_g_bIsLOGInit )
		LOG_fn_vInit();

	EnterCriticalSection(&LOG_g_stErrorOperation);

	if ( !LOG_M_bModuleExists(xModuleId) )
	{
		char szBuffer[32];
		sprintf(szBuffer, "Module id #%d", xModuleId);
		LOG_M_vLogIdEx(g_xLOGModuleId, LOG_Err_ModuleNotExist, szBuffer);

		LeaveCriticalSection(&LOG_g_stErrorOperation);
		return;
	}

	LOG_tdstModule *p_stModule = LOG_M_pstGetModuleById(xModuleId);
	LOG_tdstErrorTab *p_stTab = calloc(1, sizeof(LOG_tdstErrorTab));

	if ( !p_stTab )
	{
		LOG_M_vLogId(g_xLOGModuleId, LOG_Err_AllocError);
		LeaveCriticalSection(&LOG_g_stErrorOperation);
		return;
	}

	p_stTab->d_szErrorMsg = d_szErrorMsg;
	p_stTab->ulNbError = ulNbError;
	p_stTab->uwIdStartOfWarning = uwIdStartOfWarning;
	p_stTab->uwIdStartOfInformation = uwIdStartOfInformation;

	p_stModule->p_stErrorTab = p_stTab;

	LeaveCriticalSection(&LOG_g_stErrorOperation);
}


/****************************************************************************
 * Error management
 ****************************************************************************/

void LOG_fn_vUpdateLastError( LOG_tdstErrorInfo *p_stError, char *szExtraMsg )
{
	char *szErrHeader;
	BOOL bUnknownErr = FALSE;
	BOOL bAboutToStop = FALSE;

	if ( !szExtraMsg )
		szExtraMsg = "";

	if ( p_stError->eType == LOG_E_Information )
	{
		szErrHeader = "Just for information:";

		if ( p_stError->xModuleId == LOG_C_DefaultModule )
		{
			LOG_fn_vOutputErrorMsg(
				LOG_g_hLogFile, FALSE,
				"%s\nIn file '%s', line %d:\n    ->  %s\n        %s\n",
				szErrHeader,
				p_stError->szFileName, p_stError->uwLineNum,
				p_stError->szErrorMsg,
				szExtraMsg
			);
		}
		else
		{
			LOG_tdstModule *p_stModule = LOG_M_pstGetModuleById(p_stError->xModuleId);

			LOG_fn_vOutputErrorMsg(
				LOG_g_hLogFile, FALSE,
				"%s\nFrom %s: '%s' of %s, in file '%s', line %d:\n    ->  %s\n        %s\n",
				szErrHeader,
				p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
				p_stError->szFileName, p_stError->uwLineNum,
				p_stError->szErrorMsg,
				szExtraMsg
			);
		}

		LOG_g_stLastErrorInfo = *p_stError;
		return;
	}

	LOG_fn_vPrintToFile("\n================================================================================\n",
						LOG_g_hLogFile);

	switch ( p_stError->eType )
	{
	case LOG_E_Fatal:
		LOG_g_bSuppressInfoWindow = FALSE;
		bAboutToStop = TRUE;
		szErrHeader = "Fatal Error:";
		break;

	case LOG_E_Warning:
		szErrHeader = "Warning Error:";
		break;

	default:
		bUnknownErr = TRUE;
		szErrHeader = "Unknown Error:";
		break;
	}

	if ( p_stError->xModuleId == LOG_C_DefaultModule )
	{
		LOG_fn_vOutputErrorMsg(
			LOG_g_hLogFile, TRUE,
			"%s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			p_stError->szFileName, p_stError->uwLineNum,
			p_stError->szErrorMsg,
			szExtraMsg
		);
	}
	else
	{
		LOG_tdstModule *p_stModule = LOG_M_pstGetModuleById(p_stError->xModuleId);

		LOG_fn_vOutputErrorMsg(
			LOG_g_hLogFile, TRUE,
			"%s\nFrom %s: '%s' of %s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
			p_stError->szFileName, p_stError->uwLineNum,
			p_stError->szErrorMsg,
			szExtraMsg
		);
	}

	LOG_fn_vPrintToFile("================================================================================\n\n",
						LOG_g_hLogFile);

	LOG_g_stLastErrorInfo = *p_stError;

	if ( bUnknownErr )
		LOG_M_vLogId(g_xLOGModuleId, LOG_Err_UnknownErrType);

	/* If error is fatal, we are about to crash */
	if ( bAboutToStop )
	{
		if ( LOG_fn_bAskForDebug() )
			DebugBreak();

		LOG_fn_vCloseApp();
	}
}

LOG_tdstErrorInfo * LOG_fn_p_stGetLastError( LOG_tdxModuleId xModuleId )
{
	LOG_tdstErrorInfo *p_stInfo = (LOG_M_bModuleExists(xModuleId))
		? &LOG_M_pstGetModuleById(xModuleId)->stLastErrorForModule
		: &LOG_g_stLastErrorInfo;

	return p_stInfo;
}

void LOG_fn_vError(
	LOG_tdeErrorType eType,
	LOG_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szMsg,
	char *szExtraMsg
	)
{
	LOG_tdstErrorInfo stError = { 0 };

	if ( !LOG_g_bIsLOGInit )
		LOG_fn_vInit();

	EnterCriticalSection(&LOG_g_stErrorOperation);

	if ( strlen(szMsg) >= LOG_C_MaxErrorMsg )
		LOG_M_vLogId(g_xLOGModuleId, LOG_Err_MsgTooLong);

	strncpy(stError.szErrorMsg, szMsg, LOG_C_MaxErrorMsg - 1);
	stError.szErrorMsg[LOG_C_MaxErrorMsg-1] = '\0';
	stError.eType = eType;
	stError.xModuleId = LOG_C_DefaultModule;
	stError.szFileName = szInFile;
	stError.uwLineNum = uwAtLine;

	if ( LOG_M_bModuleExists(xModuleId) )
	{
		stError.xModuleId = xModuleId;
		LOG_M_pstGetModuleById(xModuleId)->stLastErrorForModule = stError;
	}
	LOG_fn_vUpdateLastError(&stError, szExtraMsg);

	LeaveCriticalSection(&LOG_g_stErrorOperation);
}

void LOG_fn_vErrorFromId(
	unsigned short uwErrorId,
	LOG_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szExtraMsg
	)
{
	LOG_tdstErrorInfo stError = { 0 };
	char szBuffer[30];

	if ( !LOG_g_bIsLOGInit )
		LOG_fn_vInit();

	EnterCriticalSection(&LOG_g_stErrorOperation);

	if ( !LOG_M_bModuleExists(xModuleId) )
	{
		sprintf(szBuffer, "Module id #%d", xModuleId);
		LOG_M_vLogIdEx(g_xLOGModuleId, LOG_Err_ModuleNotExist, szBuffer);

		LeaveCriticalSection(&LOG_g_stErrorOperation);
		return;
	}

	LOG_tdstModule *p_stModule = LOG_M_pstGetModuleById(xModuleId);
	LOG_tdstErrorTab *p_stTab = p_stModule->p_stErrorTab;

	if ( !p_stTab )
	{
		sprintf(szBuffer, "Module id #%d", xModuleId);
		LOG_M_vLogIdEx(g_xLOGModuleId, LOG_Err_NoErrTab, szBuffer);

		LeaveCriticalSection(&LOG_g_stErrorOperation);
		return;
	}

	if ( uwErrorId >= p_stTab->ulNbError )
	{
		sprintf(szBuffer, "Module id #%d", xModuleId);
		LOG_M_vLogIdEx(g_xLOGModuleId, LOG_Err_BadErrId, szBuffer);

		LeaveCriticalSection(&LOG_g_stErrorOperation);
		return;
	}

	LOG_tdeErrorType eType =
		(uwErrorId < p_stTab->uwIdStartOfWarning)
			? LOG_E_Fatal
			: (uwErrorId < p_stTab->uwIdStartOfInformation)
				? LOG_E_Warning
				: LOG_E_Information;

	if ( strlen(p_stTab->d_szErrorMsg[uwErrorId]) >= LOG_C_MaxErrorMsg )
		LOG_M_vLogId(g_xLOGModuleId, LOG_Err_MsgTooLong);

	strncpy(stError.szErrorMsg, p_stTab->d_szErrorMsg[uwErrorId], LOG_C_MaxErrorMsg - 1);
	stError.szErrorMsg[LOG_C_MaxErrorMsg-1] = '\0';
	stError.eType = eType;
	stError.uwErrorId = uwErrorId;
	stError.xModuleId = xModuleId;
	stError.szFileName = szInFile;
	stError.uwLineNum = uwAtLine;

	p_stModule->stLastErrorForModule = stError;
	LOG_fn_vUpdateLastError(&stError, szExtraMsg);

	LeaveCriticalSection(&LOG_g_stErrorOperation);
}

/* Clear the #define for other modules */
#undef LOG_USE_MODULE
