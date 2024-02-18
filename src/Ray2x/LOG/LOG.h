/****************************************************************************
 *
 * LOG - Spitfire's Log Module
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "Ray2x/apidefx.h"


/* Initialize the LOG module. Required before using the log functions */
ACPX_API void LOG_fn_vInit( void );


/* Print an information to log */
ACPX_API void LOG_fn_vInfo( char const *szFmt, ... );
/* Print a warning to log */
ACPX_API void LOG_fn_vWarn( char const *szFmt, ... );
/* Print an error to log */
ACPX_API void LOG_fn_vError( char const *szFmt, ... );
/* Print a fatal (unrecoverable) error to log, then shutdown the engine */
ACPX_API void LOG_fn_vErrorFatal( char const *szFmt, ... );


/* Print an information to log, with function name */
#define LOG_M_vInfoInFunc( szFmt, ... ) LOG_fn_vInfoEx(NULL, 0, __func__, (szFmt), __VA_ARGS__)
/* Print an information to log, with file and line no. */
#define LOG_M_vInfoInFile( szFmt, ... ) LOG_fn_vInfoEx(__FILE__, __LINE__, NULL, (szFmt), __VA_ARGS__)
/* Print an information to log, with file, line, and function */
#define LOG_M_vInfoEx( szFmt, ... ) LOG_fn_vInfoEx(__FILE__, __LINE__, __func__, (szFmt), __VA_ARGS__)

/* Print a warning to log, with function name */
#define LOG_M_vWarnInFunc( szFmt, ... ) LOG_fn_vWarnEx(NULL, 0, __func__, (szFmt), __VA_ARGS__)
/* Print a warning to log, with file and line no. */
#define LOG_M_vWarnInFile( szFmt, ... ) LOG_fn_vWarnEx(__FILE__, __LINE__, NULL, (szFmt), __VA_ARGS__)
/* Print a warning to log, with file, line, and function */
#define LOG_M_vWarnEx( szFmt, ... ) LOG_fn_vWarnEx(__FILE__, __LINE__, __func__, (szFmt), __VA_ARGS__)

/* Print an error to log, with function name */
#define LOG_M_vErrorInFunc( szFmt, ... ) LOG_fn_vErrorEx(NULL, 0, __func__, (szFmt), __VA_ARGS__)
/* Print an error to log, with file and line no. */
#define LOG_M_vErrorInFile( szFmt, ... ) LOG_fn_vErrorEx(__FILE__, __LINE__, NULL, (szFmt), __VA_ARGS__)
/* Print an error to log, with file, line, and function */
#define LOG_M_vErrorEx( szFmt, ... ) LOG_fn_vErrorEx(__FILE__, __LINE__, __func__, (szFmt), __VA_ARGS__)

/* Print a fatal (unrecoverable) error to log, with function name, then shutdown the engine */
#define LOG_M_vErrorFatalInFunc( szFmt, ... ) LOG_fn_vErrorFatalEx(NULL, 0, __func__, (szFmt), __VA_ARGS__)
/* Print a fatal (unrecoverable) error to log, with file and line no., then shutdown the engine */
#define LOG_M_vErrorFatalInFile( szFmt, ... ) LOG_fn_vErrorFatalEx(__FILE__, __LINE__, NULL, (szFmt), __VA_ARGS__)
/* Print a fatal (unrecoverable) error to log, with file, line, and function, then shutdown the engine */
#define LOG_M_vErrorFatalEx( szFmt, ... ) LOG_fn_vErrorFatalEx(__FILE__, __LINE__, __func__, (szFmt), __VA_ARGS__)


ACPX_API void LOG_fn_vInfoEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... );
ACPX_API void LOG_fn_vWarnEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... );
ACPX_API void LOG_fn_vErrorEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... );
ACPX_API void LOG_fn_vErrorFatalEx( char const *szFile, unsigned long ulLine, char const *szFunction, char const *szFmt, ... );
