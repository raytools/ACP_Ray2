/****************************************************************************
*
* INO - InOut Module
*
****************************************************************************/

#include "INO.h"


unsigned short *const INO_g_uwActiveKeyNumber = OFFSET(0x506B60);
unsigned short *const INO_g_a_wActiveKey = OFFSET(0x506C80);

short (*INO_fn_wInit)( HANDLE hInstance, HANDLE hWnd ) = OFFSET(0x494CF0);
short (*INO_fn_wReadKeyboard)( INO_tdstDevice *hDevice ) = OFFSET(0x496590);
