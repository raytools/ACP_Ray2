/****************************************************************************
 *
 * CLG - Compatible Log & Error Module
 *
 ****************************************************************************/

/* CLG is a module in itself */
#define CLG_USE_MODULE

#include "CLG.h"
#include "private/CLG_IO.h"
#include "private/CLG_Modules.h"
#include "GAM/GAM.h"
#include "private/framework.h"


/****************************************************************************
 * CLG module info
 ****************************************************************************/
#define CLG_C_szCLGModuleVersion	"CLG V1.2.1"
#define CLG_C_szCLGModuleName		"Compatible Log & Error Module"
#define CLG_C_szCLGModuleDate		"Feb 17 2024"

/****************************************************************************
 * Private error tab for CLG
 ****************************************************************************/
enum CLG_tdeCLGErrTab
{
#define M_DefineError(name, msg) name,
	M_DefineError(CLG_E_StartOfFatal, "")
	M_DefineError(CLG_Err_AllocError, "Memory allocation error! NULL pointer returned")
	M_DefineError(CLG_Err_TooManyModules, "Too many modules, please increase LOG_C_MaxModules")
	M_DefineError(CLG_E_StartOfWarning, "")
	M_DefineError(CLG_Err_ModuleNotExist, "Module does not exist")
	M_DefineError(CLG_Err_UnknownErrType, "Trying to raise an unknown error type")
	M_DefineError(CLG_Err_MsgTooLong, "Error message is too long and will be truncated")
	M_DefineError(CLG_Err_NoErrTab, "Module's error table missing! Set error table first with LOG_fn_vModuleUseErrorTab")
	M_DefineError(CLG_Err_BadErrId, "Bad error ID - out of bounds of the module's error table")
	M_DefineError(CLG_E_StartOfInfo, "")
#undef M_DefineError
	CLG_NbErr
};

char *g_a_szCLGErrTab[CLG_NbErr] =
{
#define M_DefineError(name, msg) msg,
	M_DefineError(CLG_E_StartOfFatal, "")
	M_DefineError(CLG_Err_AllocError, "Memory allocation error! NULL pointer returned")
	M_DefineError(CLG_Err_TooManyModules, "Too many modules, please increase LOG_C_MaxModules")
	M_DefineError(CLG_E_StartOfWarning, "")
	M_DefineError(CLG_Err_ModuleNotExist, "Module does not exist")
	M_DefineError(CLG_Err_UnknownErrType, "Trying to raise an unknown error type")
	M_DefineError(CLG_Err_MsgTooLong, "Error message is too long and will be truncated")
	M_DefineError(CLG_Err_NoErrTab, "Module's error table missing! Set error table first with LOG_fn_vModuleUseErrorTab")
	M_DefineError(CLG_Err_BadErrId, "Bad error ID - out of bounds of the module's error table")
	M_DefineError(CLG_E_StartOfInfo, "")
#undef M_DefineError
};
/****************************************************************************/


CRITICAL_SECTION CLG_g_stErrorOperation = { 0 };

BOOL CLG_g_bIsCLGInit = FALSE;

CLG_tdstModule *CLG_g_a_pstModuleTab[CLG_C_MaxModules] = { 0 };
CLG_tdxModuleId CLG_g_xNbOfModule = 0;

CLG_tdstErrorInfo CLG_g_stLastErrorInfo = { 0 };
FILE *CLG_g_hLogFile = NULL;

CLG_tdxModuleId g_xCLGModuleId = CLG_C_DefaultModule;


/****************************************************************************
 * Init function
 ****************************************************************************/

void CLG_fn_vInit( void )
{
	if ( CLG_g_bIsCLGInit )
		return;
	CLG_g_bIsCLGInit = TRUE;

	InitializeCriticalSection(&CLG_g_stErrorOperation);
	CLG_g_hLogFile = CLG_fn_hOpenFileForWrite(CLG_C_szLogFileName);
	g_xCLGModuleId = CLG_fn_xRegisterModule(CLG_C_szCLGModuleVersion, CLG_C_szCLGModuleName, CLG_C_szCLGModuleDate);
	CLG_fn_vModuleUseErrorTab(g_xCLGModuleId, g_a_szCLGErrTab, CLG_NbErr, CLG_E_StartOfWarning, CLG_E_StartOfInfo);
}

void CLG_fn_vCloseApp( void )
{
	CLG_fn_vCloseFile(CLG_g_hLogFile);
	GAM_fn_vChangeEngineMode(E_EM_ModeStoppingProgram);
}


/****************************************************************************
 * Module management
 ****************************************************************************/

CLG_tdxModuleId CLG_fn_xRegisterModule( char const *szCodeAndVersion, char const *szFullName, char const *szDate )
{
	if ( !CLG_g_bIsCLGInit )
		CLG_fn_vInit();

	EnterCriticalSection(&CLG_g_stErrorOperation);

	if ( CLG_g_xNbOfModule >= CLG_C_MaxModules )
	{
		CLG_M_vLogId(g_xCLGModuleId, CLG_Err_TooManyModules);
		LeaveCriticalSection(&CLG_g_stErrorOperation);
		return CLG_C_DefaultModule;
	}

	CLG_tdxModuleId xModuleId = CLG_g_xNbOfModule++;

	CLG_tdstModule *pModule = calloc(1, sizeof(CLG_tdstModule));

	if ( !pModule )
	{
		CLG_M_vLogId(g_xCLGModuleId, CLG_Err_AllocError);
		LeaveCriticalSection(&CLG_g_stErrorOperation);
		return CLG_C_DefaultModule;
	}

	pModule->szCodeVersion = szCodeAndVersion;
	pModule->szFullName = szFullName;
	pModule->szDate = szDate;

	CLG_M_pstGetModuleById(xModuleId) = pModule;

	char szBuffer[256];
	sprintf(szBuffer, "The module [%s : '%s' of %s] is initialized with the id #%d",
				pModule->szCodeVersion, pModule->szFullName, pModule->szDate, xModuleId);

	CLG_M_vLogInfo(CLG_C_DefaultModule, szBuffer);

	LeaveCriticalSection(&CLG_g_stErrorOperation);
	return xModuleId;
}

void CLG_fn_vModuleUseErrorTab( CLG_tdxModuleId xModuleId, char const **d_szErrorMsg, unsigned long ulNbError,
								unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation )
{
	if ( !CLG_g_bIsCLGInit )
		CLG_fn_vInit();

	EnterCriticalSection(&CLG_g_stErrorOperation);

	if ( !CLG_M_bModuleExists(xModuleId) )
	{
		char szBuffer[32];
		sprintf(szBuffer, "Module id #%d", xModuleId);
		CLG_M_vLogIdEx(g_xCLGModuleId, CLG_Err_ModuleNotExist, szBuffer);

		LeaveCriticalSection(&CLG_g_stErrorOperation);
		return;
	}

	CLG_tdstModule *p_stModule = CLG_M_pstGetModuleById(xModuleId);
	CLG_tdstErrorTab *p_stTab = calloc(1, sizeof(CLG_tdstErrorTab));

	if ( !p_stTab )
	{
		CLG_M_vLogId(g_xCLGModuleId, CLG_Err_AllocError);
		LeaveCriticalSection(&CLG_g_stErrorOperation);
		return;
	}

	p_stTab->d_szErrorMsg = d_szErrorMsg;
	p_stTab->ulNbError = ulNbError;
	p_stTab->uwIdStartOfWarning = uwIdStartOfWarning;
	p_stTab->uwIdStartOfInformation = uwIdStartOfInformation;

	p_stModule->p_stErrorTab = p_stTab;

	LeaveCriticalSection(&CLG_g_stErrorOperation);
}


/****************************************************************************
 * Error management
 ****************************************************************************/

void CLG_fn_vUpdateLastError( CLG_tdstErrorInfo *p_stError, char const *szExtraMsg )
{
	char *szErrHeader;
	char cExtraLine = '\n';
	BOOL bUnknownErr = FALSE;
	BOOL bAboutToStop = FALSE;

	if ( !szExtraMsg )
	{
		szExtraMsg = "";
		cExtraLine = 0;
	}

	if ( p_stError->eType == CLG_E_Information )
	{
		szErrHeader = "Just for information:";

		if ( p_stError->xModuleId == CLG_C_DefaultModule )
		{
			CLG_fn_vOutputErrorMsg(
				CLG_g_hLogFile, FALSE,
				"%s\nIn file '%s', line %d:\n    ->  %s\n%s\n%c",
				szErrHeader,
				p_stError->szFileName, p_stError->uwLineNum,
				p_stError->szErrorMsg,
				szExtraMsg, cExtraLine
			);
		}
		else
		{
			CLG_tdstModule *p_stModule = CLG_M_pstGetModuleById(p_stError->xModuleId);

			CLG_fn_vOutputErrorMsg(
				CLG_g_hLogFile, FALSE,
				"%s\nFrom %s: '%s' of %s, in file '%s', line %d:\n    ->  %s\n%s\n%c",
				szErrHeader,
				p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
				p_stError->szFileName, p_stError->uwLineNum,
				p_stError->szErrorMsg,
				szExtraMsg, cExtraLine
			);
		}

		CLG_g_stLastErrorInfo = *p_stError;
		return;
	}

	CLG_fn_vPrintToFile("================================================================================\n",
						CLG_g_hLogFile);

	switch ( p_stError->eType )
	{
	case CLG_E_Fatal:
		CLG_g_bSuppressInfoWindow = FALSE;
		bAboutToStop = TRUE;
		szErrHeader = "Fatal Error:";
		break;

	case CLG_E_Warning:
		szErrHeader = "Warning Error:";
		break;

	default:
		bUnknownErr = TRUE;
		szErrHeader = "Unknown Error:";
		break;
	}

	if ( p_stError->xModuleId == CLG_C_DefaultModule )
	{
		CLG_fn_vOutputErrorMsg(
			CLG_g_hLogFile, TRUE,
			"%s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			p_stError->szFileName, p_stError->uwLineNum,
			p_stError->szErrorMsg,
			szExtraMsg
		);
	}
	else
	{
		CLG_tdstModule *p_stModule = CLG_M_pstGetModuleById(p_stError->xModuleId);

		CLG_fn_vOutputErrorMsg(
			CLG_g_hLogFile, TRUE,
			"%s\nFrom %s: '%s' of %s\nIn file '%s', line %d:\n\n-> %s <-\n%s\n",
			szErrHeader,
			p_stModule->szCodeVersion, p_stModule->szFullName, p_stModule->szDate,
			p_stError->szFileName, p_stError->uwLineNum,
			p_stError->szErrorMsg,
			szExtraMsg
		);
	}

	CLG_fn_vPrintToFile("================================================================================\n\n",
						CLG_g_hLogFile);

	CLG_g_stLastErrorInfo = *p_stError;

	if ( bUnknownErr )
		CLG_M_vLogId(g_xCLGModuleId, CLG_Err_UnknownErrType);

	/* If error is fatal, we are about to crash */
	if ( bAboutToStop )
	{
		if ( CLG_fn_bAskForDebug() )
			DebugBreak();

		CLG_fn_vCloseApp();
	}
}

CLG_tdstErrorInfo * CLG_fn_p_stGetLastError( CLG_tdxModuleId xModuleId )
{
	CLG_tdstErrorInfo *p_stInfo = (CLG_M_bModuleExists(xModuleId))
		? &CLG_M_pstGetModuleById(xModuleId)->stLastErrorForModule
		: &CLG_g_stLastErrorInfo;

	return p_stInfo;
}

void CLG_fn_vError(
	CLG_tdeErrorType eType,
	CLG_tdxModuleId xModuleId,
	char const *szInFile,
	unsigned short uwAtLine,
	char const *szMsg,
	char const *szExtraMsg
	)
{
	CLG_tdstErrorInfo stError = { 0 };

	if ( !CLG_g_bIsCLGInit )
		CLG_fn_vInit();

	EnterCriticalSection(&CLG_g_stErrorOperation);

	if ( strlen(szMsg) >= CLG_C_MaxErrorMsg )
		CLG_M_vLogId(g_xCLGModuleId, CLG_Err_MsgTooLong);

	strncpy(stError.szErrorMsg, szMsg, CLG_C_MaxErrorMsg - 1);
	stError.szErrorMsg[CLG_C_MaxErrorMsg-1] = '\0';
	stError.eType = eType;
	stError.xModuleId = CLG_C_DefaultModule;
	stError.szFileName = szInFile;
	stError.uwLineNum = uwAtLine;

	if ( CLG_M_bModuleExists(xModuleId) )
	{
		stError.xModuleId = xModuleId;
		CLG_M_pstGetModuleById(xModuleId)->stLastErrorForModule = stError;
	}
	CLG_fn_vUpdateLastError(&stError, szExtraMsg);

	LeaveCriticalSection(&CLG_g_stErrorOperation);
}

void CLG_fn_vErrorFromId(
	unsigned short uwErrorId,
	CLG_tdxModuleId xModuleId,
	char const *szInFile,
	unsigned short uwAtLine,
	char const *szExtraMsg
	)
{
	CLG_tdstErrorInfo stError = { 0 };
	char szBuffer[30];

	if ( !CLG_g_bIsCLGInit )
		CLG_fn_vInit();

	EnterCriticalSection(&CLG_g_stErrorOperation);

	if ( !CLG_M_bModuleExists(xModuleId) )
	{
		sprintf(szBuffer, "Module id #%d", xModuleId);
		CLG_M_vLogIdEx(g_xCLGModuleId, CLG_Err_ModuleNotExist, szBuffer);

		LeaveCriticalSection(&CLG_g_stErrorOperation);
		return;
	}

	CLG_tdstModule *p_stModule = CLG_M_pstGetModuleById(xModuleId);
	CLG_tdstErrorTab *p_stTab = p_stModule->p_stErrorTab;

	if ( !p_stTab )
	{
		sprintf(szBuffer, "Module id #%d", xModuleId);
		CLG_M_vLogIdEx(g_xCLGModuleId, CLG_Err_NoErrTab, szBuffer);

		LeaveCriticalSection(&CLG_g_stErrorOperation);
		return;
	}

	if ( uwErrorId >= p_stTab->ulNbError )
	{
		sprintf(szBuffer, "Module id #%d", xModuleId);
		CLG_M_vLogIdEx(g_xCLGModuleId, CLG_Err_BadErrId, szBuffer);

		LeaveCriticalSection(&CLG_g_stErrorOperation);
		return;
	}

	CLG_tdeErrorType eType =
		(uwErrorId < p_stTab->uwIdStartOfWarning)
			? CLG_E_Fatal
			: (uwErrorId < p_stTab->uwIdStartOfInformation)
				? CLG_E_Warning
				: CLG_E_Information;

	if ( strlen(p_stTab->d_szErrorMsg[uwErrorId]) >= CLG_C_MaxErrorMsg )
		CLG_M_vLogId(g_xCLGModuleId, CLG_Err_MsgTooLong);

	strncpy(stError.szErrorMsg, p_stTab->d_szErrorMsg[uwErrorId], CLG_C_MaxErrorMsg - 1);
	stError.szErrorMsg[CLG_C_MaxErrorMsg-1] = '\0';
	stError.eType = eType;
	stError.uwErrorId = uwErrorId;
	stError.xModuleId = xModuleId;
	stError.szFileName = szInFile;
	stError.uwLineNum = uwAtLine;

	p_stModule->stLastErrorForModule = stError;
	CLG_fn_vUpdateLastError(&stError, szExtraMsg);

	LeaveCriticalSection(&CLG_g_stErrorOperation);
}

/* Clear the #define for other modules */
#undef CLG_USE_MODULE
