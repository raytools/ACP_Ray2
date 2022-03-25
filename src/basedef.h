/****************************************************************************
 *
 * Base type definitions for ACP
 *
 ****************************************************************************/

#pragma once


#ifndef NULL
	#define NULL	((void*)0)
#endif
#ifndef FALSE
	#define FALSE	0
#endif
#ifndef TRUE
	#define TRUE	1
#endif

typedef int BOOL;
typedef unsigned char ACP_tdxBool; /* size of ACP_tdxBool : 1 byte */

/****************************************************************************/
/* TODO: remove these */
typedef void *HANDLE;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
/****************************************************************************/

typedef signed short ACP_tdxIndex;
typedef unsigned long ACP_tdxAddress;
