/****************************************************************************
 *
 * CLG - Compatible Log & Error Module
 *
 ****************************************************************************/

#pragma once

#include "CLG_Def.h"
#include "basedef.h"
#include "Ray2x/apidefx.h"


ACPX_API void CLG_fn_vInit( void );

/* Register the module. Recommended format for szCodeAndVersion is "XXX V1.2.3". */
ACPX_API CLG_tdxModuleId CLG_fn_xRegisterModule( char const *szCodeAndVersion, char const *szFullName, char const *szDate );

/* Register error table for the module. The table should be structured as such:
   (0 <= n < uwIdStartOfWarning) are fatal errors
   (uwIdStartOfWarning <= n < uwIdStartOfInformation) are warnings
   (uwIdStartOfInformation <= n < ulNbError) are informations */
ACPX_API void CLG_fn_vModuleUseErrorTab( CLG_tdxModuleId xModuleId, char const **d_szErrorMsg, unsigned long ulNbError,
										unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation );

ACPX_API CLG_tdstErrorInfo * CLG_fn_p_stGetLastError( CLG_tdxModuleId xModuleId );


/* Note: Use the provided macros (CLG_M_vLogXXX) instead!
   To use module ID, define CLG_USE_MODULE or use CLG_M_vLog***Ex macros. */
ACPX_API void CLG_fn_vError(
	CLG_tdeErrorType eType,
	CLG_tdxModuleId xModuleId,
	char const *szInFile,
	unsigned short uwAtLine,
	char const *szMsg,
	char const *szExtraMsg
);

/* Note: Use the provided macros (CLG_M_vLogId and CLG_M_vLogIdEx) instead! */
ACPX_API void CLG_fn_vErrorFromId(
	unsigned short uwErrorId,
	CLG_tdxModuleId xModuleId,
	char const *szInFile,
	unsigned short uwAtLine,
	char const *szExtraMsg
);


#ifdef CLG_USE_MODULE

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with module ID) */
#define CLG_M_vLogFatal(xModuleId, szMsg) CLG_fn_vError(CLG_E_Fatal, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)
/* Write a warning to the log and display an information window (with module ID) */
#define CLG_M_vLogWarning(xModuleId, szMsg) CLG_fn_vError(CLG_E_Warning, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)
/* Write an information string to the log (with module ID) */
#define CLG_M_vLogInfo(xModuleId, szMsg) CLG_fn_vError(CLG_E_Information, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with extra message line) */
#define CLG_M_vLogFatalEx(xModuleId, szMsg, szExtraMsg) CLG_fn_vError(CLG_E_Fatal, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write a warning to the log and display an information window (with extra message line) */
#define CLG_M_vLogWarningEx(xModuleId, szMsg, szExtraMsg) CLG_fn_vError(CLG_E_Warning, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write an information string to the log (with extra message line) */
#define CLG_M_vLogInfoEx(xModuleId, szMsg, szExtraMsg) CLG_fn_vError(CLG_E_Information, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))

/* Write a predefined error from the module's error table to the log */
#define CLG_M_vLogId(xModuleId, uwErrorId) CLG_fn_vErrorFromId((uwErrorId), (xModuleId), __FILE__, __LINE__, NULL)
/* Write a predefined error from the module's error table to the log (with extra message line) */
#define CLG_M_vLogIdEx(xModuleId, uwErrorId, szExtraMsg) CLG_fn_vErrorFromId((uwErrorId), (xModuleId), __FILE__, __LINE__, (szExtraMsg))

#else

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game */
#define CLG_M_vLogFatal(szMsg) CLG_fn_vError(CLG_E_Fatal, CLG_C_DefaultModule, __FILE__, __LINE__, (szMsg), NULL)
/* Write a warning to the log and display an information window */
#define CLG_M_vLogWarning(szMsg) CLG_fn_vError(CLG_E_Warning, CLG_C_DefaultModule, __FILE__, __LINE__, (szMsg), NULL)
/* Write an information string to the log */
#define CLG_M_vLogInfo(szMsg) CLG_fn_vError(CLG_E_Information, CLG_C_DefaultModule, __FILE__, __LINE__, (szMsg), NULL)

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with extra message line) */
#define CLG_M_vLogFatalEx(szMsg, szExtraMsg) CLG_fn_vError(CLG_E_Fatal, CLG_C_DefaultModule, __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write a warning to the log and display an information window (with extra message line) */
#define CLG_M_vLogWarningEx(szMsg, szExtraMsg) CLG_fn_vError(CLG_E_Warning, CLG_C_DefaultModule, __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write an information string to the log (with extra message line) */
#define CLG_M_vLogInfoEx(szMsg, szExtraMsg) CLG_fn_vError(CLG_E_Information, CLG_C_DefaultModule, __FILE__, __LINE__, (szMsg), (szExtraMsg))

#endif
