#pragma once


#define ERR_Error(szMsg) ERR_fn_vPrintError(szMsg, __func__, (short)__LINE__, __FILE__)
#define ERR_Warning(szMsg) ERR_fn_vPrintWarning(szMsg, __func__, (short)__LINE__, __FILE__)
#define ERR_Info(szMsg) ERR_fn_vPrintInfo(szMsg, __func__)

void ERR_fn_vInit( void );

void ERR_fn_vPrintError( char const *szMsg, char const *szFunc, short wLineNum, char const *szFile );
void ERR_fn_vPrintWarning( char const *szMsg, char const *szFunc, short wLineNum, char const *szFile );
void ERR_fn_vPrintInfo( char const *szMsg, char const *szFunc );
