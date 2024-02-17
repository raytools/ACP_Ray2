/****************************************************************************
 * CLG - I/O header
 ****************************************************************************/

#pragma once

#include "../CLG.h"
#include "private/framework.h"


#define CLG_C_szLogFileName "CPALog2.log"


extern FILE *CLG_g_hLogFile;
extern BOOL CLG_g_bSuppressInfoWindow;


FILE * CLG_fn_hOpenFileForWrite( char *szFilePath );
void CLG_fn_vCloseFile( FILE *hFile );

void CLG_fn_vPrintToFile( char *szText, FILE *hFile );
void CLG_fn_vPrintToInfoWindow( char *szText );

BOOL CLG_fn_bAskForDebug( void );

void CLG_fn_vOutputErrorMsg( FILE *hFile, BOOL bInfoWindow, char const *szFormat, ... );
