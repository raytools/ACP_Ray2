/****************************************************************************
 * LOG - I/O header
 ****************************************************************************/

#pragma once

#include "LOG/LOG.h"
#include "private/framework.h"


#define LOG_C_szLogFileName "CPALog.log"


extern FILE *LOG_g_hLogFile;
extern BOOL LOG_g_bSuppressInfoWindow;


FILE * LOG_fn_hOpenFileForWrite( char *szFilePath );
void LOG_fn_vCloseFile( FILE *hFile );

void LOG_fn_vPrintToFile( char *szText, FILE *hFile );
void LOG_fn_vPrintToInfoWindow( char *szText );

BOOL LOG_fn_bAskForDebug( void );

void LOG_fn_vOutputErrorMsg( FILE *hFile, BOOL bInfoWindow, char const *szFormat, ... );
