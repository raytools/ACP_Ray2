/****************************************************************************
 *
 * LOG - Spitfire's Log & Error Module
 *
 ****************************************************************************/

#pragma once

#include "LOG_Def.h"
#include "basedef.h"
#include "apidef.h"


ACP_API void LOG_fn_vInit( void );

/* Register the module. Recommended format for szCodeAndVersion is "XXX V1.2.3". */
ACP_API LOG_tdxModuleId LOG_fn_xRegisterModule( char const *szCodeAndVersion, char const *szFullName, char const *szDate );

/* Register error table for the module. The table should be structured as such:
   (0 <= n < uwIdStartOfWarning) are fatal errors
   (uwIdStartOfWarning <= n < uwIdStartOfInformation) are warnings
   (uwIdStartOfInformation <= n < ulNbError) are informations */
ACP_API void LOG_fn_vModuleUseErrorTab( LOG_tdxModuleId xModuleId, char **d_szErrorMsg, unsigned long ulNbError,
										unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation );

ACP_API LOG_tdstErrorInfo * LOG_fn_p_stGetLastError( LOG_tdxModuleId xModuleId );


/* Note: Use the provided macros (LOG_M_vLogXXX) instead!
   To use module ID, define LOG_USE_MODULE or use LOG_M_vLog***Ex macros. */
ACP_API void LOG_fn_vError(
	LOG_tdeErrorType eType,
	LOG_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szMsg,
	char *szExtraMsg
);

/* Note: Use the provided macros (LOG_M_vLogId and LOG_M_vLogIdEx) instead! */
ACP_API void LOG_fn_vErrorFromId(
	unsigned short uwErrorId,
	LOG_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szExtraMsg
);


#ifdef LOG_USE_MODULE

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with module ID) */
#define LOG_M_vLogFatal(xModuleId, szMsg) LOG_fn_vError(LOG_E_Fatal, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)
/* Write a warning to the log and display an information window (with module ID) */
#define LOG_M_vLogWarning(xModuleId, szMsg) LOG_fn_vError(LOG_E_Warning, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)
/* Write an information string to the log (with module ID) */
#define LOG_M_vLogInfo(xModuleId, szMsg) LOG_fn_vError(LOG_E_Information, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with extra message line) */
#define LOG_M_vLogFatalEx(xModuleId, szMsg, szExtraMsg) LOG_fn_vError(LOG_E_Fatal, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write a warning to the log and display an information window (with extra message line) */
#define LOG_M_vLogWarningEx(xModuleId, szMsg, szExtraMsg) LOG_fn_vError(LOG_E_Warning, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write an information string to the log (with extra message line) */
#define LOG_M_vLogInfoEx(xModuleId, szMsg, szExtraMsg) LOG_fn_vError(LOG_E_Information, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))

/* Write a predefined error from the module's error table to the log */
#define LOG_M_vLogId(xModuleId, uwErrorId) LOG_fn_vErrorFromId((uwErrorId), (xModuleId), __FILE__, __LINE__, NULL)
/* Write a predefined error from the module's error table to the log (with extra message line) */
#define LOG_M_vLogIdEx(xModuleId, uwErrorId, szExtraMsg) LOG_fn_vErrorFromId((uwErrorId), (xModuleId), __FILE__, __LINE__, (szExtraMsg))

#else

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game */
#define LOG_M_vLogFatal(szMsg) LOG_fn_vError(LOG_E_Fatal, LOG_C_DefaultModule, __FILE__, __LINE__, (szMsg), NULL)
/* Write a warning to the log and display an information window */
#define LOG_M_vLogWarning(szMsg) LOG_fn_vError(LOG_E_Warning, LOG_C_DefaultModule, __FILE__, __LINE__, (szMsg), NULL)
/* Write an information string to the log */
#define LOG_M_vLogInfo(szMsg) LOG_fn_vError(LOG_E_Information, LOG_C_DefaultModule, __FILE__, __LINE__, (szMsg), NULL)

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with extra message line) */
#define LOG_M_vLogFatalEx(szMsg, szExtraMsg) LOG_fn_vError(LOG_E_Fatal, LOG_C_DefaultModule, __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write a warning to the log and display an information window (with extra message line) */
#define LOG_M_vLogWarningEx(szMsg, szExtraMsg) LOG_fn_vError(LOG_E_Warning, LOG_C_DefaultModule, __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write an information string to the log (with extra message line) */
#define LOG_M_vLogInfoEx(szMsg, szExtraMsg) LOG_fn_vError(LOG_E_Information, LOG_C_DefaultModule, __FILE__, __LINE__, (szMsg), (szExtraMsg))

#endif
