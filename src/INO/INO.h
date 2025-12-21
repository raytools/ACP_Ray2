/****************************************************************************
 *
 * INO - InOut Module
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "apidef.h"


#define INO_C_wNbMaxDevice		20
#define INO_C_wNbMaxAxis		6
#define INO_C_wMaxKeyDown		8
#define INO_C_wStringMaxLength	32


#define INO_C_ucConnected		0x01
#define INO_C_ucAcquired		0x02
#define INO_C_ucAccessError		0x04
#define INO_C_ucGLDLink			0x08
#define INO_C_ucActivated		0x10

#define INO_C_uwUnknown			0x00
#define INO_C_uwMouse			0x04
#define INO_C_uwKeyboard		0x08
#define INO_C_uwJoystick		0x10
#define INO_C_uwAnyType			0xFF


typedef struct INO_tdstDevCaps
{
	unsigned char ucNbButtons;
	unsigned int ulCapsFlags;
}
INO_tdstDevCaps;

typedef struct INO_tdstDevState
{
	unsigned char ucStatus;
}
INO_tdstDevState;

typedef short (*INO_tdfn_wMethod)( struct INO_tdstDevice *tdstDevice );

typedef struct INO_tdstDevice
{
	unsigned short uwType;
	INO_tdstDevCaps *p_stCaps;
	INO_tdstDevState *p_stState;
	unsigned int ulLastTimeCount;
	short wHistoricSize;
	short wHistoricHead;
	short wRecordNumber;
	void *pvHistoric;
	INO_tdfn_wMethod pfnRead;
}
INO_tdstDevice;


typedef struct INO_tdstKeyboardCaps
{
	unsigned char ucNbButtons;
	unsigned int ulCapsFlags;
	unsigned short wIsAzerty;
}
INO_tdstKeyboardCaps;

typedef struct INO_tdstKeyboardState
{
	unsigned char ucStatus;
	unsigned char a_ucTabKey[2][256];
	unsigned short wCurrentTab;
	unsigned short wLastKey;
	unsigned short wLastASCII;
	unsigned short wStateHasChanged;
	char szCurrentString[INO_C_wStringMaxLength];
	unsigned short wCurrentStringLength;
}
INO_tdstKeyboardState;

typedef struct INO_tdstKeyboardRecord
{
	unsigned short wNbKeyDown;
	unsigned short a_wKeyDown[INO_C_wMaxKeyDown];
	unsigned int ulDate;
}
INO_tdstKeyboardRecord;


/*
 * Variables
 */

ACP_VAR unsigned short *const INO_g_uwActiveKeyNumber;
ACP_VAR unsigned short *const INO_g_a_wActiveKey;


/*
 * Functions
 */

ACP_FUNC short (*INO_fn_wInit)( HANDLE hInstance, HANDLE hWnd );
ACP_FUNC short (*INO_fn_wReadKeyboard)( INO_tdstDevice *hDevice );
