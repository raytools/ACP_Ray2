/****************************************************************************
 * BLT - I/O header
 ****************************************************************************/

#pragma once

#include "BLT/BLT.h"
#include "private/framework.h"


#define BLT_C_szLogFileName "CPALog.log"


FILE * BLT_fn_hOpenFileForWrite( char *szFilePath );
void BLT_fn_vCloseFile( FILE *hFile );

void BLT_fn_vPrintToFile( char *szText, FILE *hFile );
void BLT_fn_vPrintToInfoWindow( char *szText );
void BLT_fn_vOutputErrorMsg( FILE *hFile, BOOL bInfoWindow, char const *szFormat, ... );
