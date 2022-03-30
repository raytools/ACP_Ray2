/****************************************************************************
 * BLT - I/O header
 ****************************************************************************/

#pragma once

#include "BLT/BLT.h"
#include "private/framework.h"


#define BLT_C_szLogFileName "CPALog.log"


extern BOOL BLT_g_bSuppressInfoWindow;


FILE * BLT_fn_hOpenFileForWrite( char *szFilePath );
void BLT_fn_vCloseFile( FILE *hFile );

void BLT_fn_vPrintToFile( char *szText, FILE *hFile );
void BLT_fn_vPrintToInfoWindow( char *szText );

BOOL BLT_fn_bAskForDebug( void );
void BLT_fn_vCloseApp( void );

void BLT_fn_vOutputErrorMsg( FILE *hFile, BOOL bInfoWindow, char const *szFormat, ... );
