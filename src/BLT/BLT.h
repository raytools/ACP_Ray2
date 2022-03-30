/****************************************************************************
 *
 * BLT - Spitfire's Better Log Tool
 *
 ****************************************************************************/

#pragma once

#include "BLT_Def.h"
#include "basedef.h"
#include "apidef.h"


ACP_API void BLT_fn_vInit( void );

ACP_API BLT_tdxModuleId BLT_fn_xRegisterModule( char const *szCodeAndVersion, char const *szFullName, char const *szDate );
ACP_API void BLT_fn_vModuleUseErrorTab( BLT_tdxModuleId xModuleId, char **d_szErrorMsg, unsigned long ulNbError,
										unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation );

ACP_API BLT_tdstErrorInfo * BLT_fn_p_stGetLastError( BLT_tdxModuleId xModuleId );


/*
 * Note:
 * Use the provided macros (BLT_M_vLogXXX) instead!
 * To use module ID, define BLT_USE_MODULE or use BLT_M_vLog***Ex macros.
 */
ACP_API void BLT_fn_vError(
	BLT_tdeErrorType eType,
	BLT_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szMsg,
	char *szExtraMsg
);

/*
 * Note:
 * Use the provided macros (BLT_M_vLogId and BLT_M_vLogIdEx) instead!
 */
ACP_API void BLT_fn_vErrorFromId(
	unsigned short uwErrorId,
	BLT_tdxModuleId xModuleId,
	char *szInFile,
	unsigned short uwAtLine,
	char *szExtraMsg
);


#ifdef BLT_USE_MODULE

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with module ID) */
#define BLT_M_vLogFatal(xModuleId, szMsg) BLT_fn_vError(BLT_E_Fatal, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)
/* Write a warning to the log and display an information window (with module ID) */
#define BLT_M_vLogWarning(xModuleId, szMsg) BLT_fn_vError(BLT_E_Warning, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)
/* Write an information string to the log (with module ID) */
#define BLT_M_vLogInfo(xModuleId, szMsg) BLT_fn_vError(BLT_E_Information, (xModuleId), __FILE__, __LINE__, (szMsg), NULL)

#else

/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game */
#define BLT_M_vLogFatal(szMsg) BLT_fn_vError(BLT_E_Fatal, 0, __FILE__, __LINE__, (szMsg), NULL)
/* Write a warning to the log and display an information window */
#define BLT_M_vLogWarning(szMsg) BLT_fn_vError(BLT_E_Warning, 0, __FILE__, __LINE__, (szMsg), NULL)
/* Write an information string to the log */
#define BLT_M_vLogInfo(szMsg) BLT_fn_vError(BLT_E_Information, 0, __FILE__, __LINE__, (szMsg), NULL)

#endif


/* Write a fatal (unrecoverable) error to the log, display an information window and exit the game (with extra message line) */
#define BLT_M_vLogFatalEx(xModuleId, szMsg, szExtraMsg) BLT_fn_vError(BLT_E_Fatal, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write a warning to the log and display an information window (with extra message line) */
#define BLT_M_vLogWarningEx(xModuleId, szMsg, szExtraMsg) BLT_fn_vError(BLT_E_Warning, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))
/* Write an information string to the log (with extra message line) */
#define BLT_M_vLogInfoEx(xModuleId, szMsg, szExtraMsg) BLT_fn_vError(BLT_E_Information, (xModuleId), __FILE__, __LINE__, (szMsg), (szExtraMsg))


/* Write a predefined error from the module's error table to the log */
#define BLT_M_vLogId(uwErrorId, xModuleId) BLT_fn_vErrorFromId((uwErrorId), (xModuleId), __FILE__, __LINE__, NULL)
/* Write a predefined error from the module's error table to the log (with extra message line) */
#define BLT_M_vLogIdEx(uwErrorId, xModuleId, szExtraMsg) BLT_fn_vErrorFromId((uwErrorId), (xModuleId), __FILE__, __LINE__, (szExtraMsg))
