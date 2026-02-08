/****************************************************************************
 *
 * IPT - Input module
 *
 ****************************************************************************/

#pragma once

#include "IPT_Def.h"
#include "IPT_Const.h"

#include "INO/INO.h"
#include "LST.h"
#include "MTH.h"
#include "basedef.h"
#include "apidef.h"


typedef struct IPT_tdstKeyAndPadDefine
{
	unsigned short uwBasedKey;
	char *p_szFrenchKey;
	char *p_szAmericanKey;
}
IPT_tdstKeyAndPadDefine;

typedef struct IPT_tdstHistoricElement
{
	unsigned char bf2State;
	unsigned char bf6DeviceType;
	unsigned char ucCounter;
	short wDeviceValue;
}
IPT_tdstHistoricElement;

typedef union IPT_tduKeyWordElementUnion
{
	short swJoyNumber;
	short swJoyAction;
	short swJoyValueMin;
	short swJoyValueMax;
	short swPadNumber;
	short swPadAction;
	short swKey;
	short swKeyWord;
	IPT_tdstEntryElement *hEntryElement;
	unsigned long ulNumberOfSequence;
}
IPT_tduKeyWordElementUnion;

typedef struct IPT_tdstKeyWordElement
{
	IPT_tduKeyWordElementUnion uElementUnion;

	unsigned char ucResult;
	unsigned char ucMinCounterInput;
	unsigned char ucMaxCounterInput;
}
IPT_tdstKeyWordElement;

typedef struct IPT_tdstEntryElement
{
	unsigned long ulNumberOfKeyWordElement;
	IPT_tdstKeyWordElement *d_stKeyWordElementArray;

	char *p_szEntryName;
	long lState; /* Pos: Counter since pressed (LONG_MAX), Neg: Counter since released (LONG_MIN) */
	MTH_tdxReal xAnalogicValue;
	BOOL bIsActivate;
}
IPT_tdstEntryElement;


typedef struct IPT_tdstInput
{
	unsigned char ucOnePadActivate;
	unsigned char a_ucValideAndActiveDevice[IPT_E_NbOfDeviceEvent];
	INO_tdstDevice *a_hINODevice[IPT_E_NbOfDeviceEvent];

	unsigned char a_ucKeyboardCounter[256];
	unsigned char a_ucPadAndJoyCounter[IPT_E_NbOfDeviceEvent][IPT_E_NbOfPadAndJoyAction];
	unsigned char ucKeyboardType;
	unsigned char a_ucMouseButtonsCounter[9]; /* Unused? */

	char _gap_06E8[24];

	unsigned long ulNumberOfEntryElement;
	IPT_tdstEntryElement *d_stEntryElementArray;
	LST_M_DynamicParentDecl(IPT_tdstEntryElement) /* Unused? */

	short sEventHistoricSize;
	IPT_tdstHistoricElement *hEventHistoric;
}
IPT_tdstInput;


/*
 * Variables
 */

ACP_VAR IPT_tdstInput *const IPT_g_stInputStructure;
ACP_VAR IPT_tdstKeyAndPadDefine *const IPT_gd_hKeyAndPadDefine;

ACP_VAR float *const IPT_g_FieldPadGlobalVectorX;
ACP_VAR float *const IPT_g_FieldPadGlobalVectorY;
ACP_VAR float *const IPT_g_FieldPadGlobalVectorZ;
ACP_VAR float *const IPT_g_FieldPadHorizontalAxis;
ACP_VAR float *const IPT_g_FieldPadVerticalAxis;
ACP_VAR float *const IPT_g_FieldPadAnalogForce;
ACP_VAR float *const IPT_g_FieldPadTrueAnalogForce;
ACP_VAR float *const IPT_g_FieldPadRotationAngle;
ACP_VAR int		*const IPT_g_FieldPadSector;

/*
 * Functions
 */

ACP_FUNC void (*IPT_fn_vResetInputEntry)( void );
ACP_FUNC void (*IPT_fn_vActualizeHistoric)(void);

ACP_FUNC ACP_tdxBool (*IPT_fn_bIsJustValidated)( IPT_tdstEntryElement *hEntryElement );
ACP_FUNC ACP_tdxBool (*IPT_fn_bIsJustInvalidated)( IPT_tdstEntryElement *hEntryElement );
ACP_FUNC ACP_tdxBool (*IPT_fn_bIsValidated)( IPT_tdstEntryElement *hEntryElement );
ACP_FUNC ACP_tdxBool (*IPT_fn_bIsInvalidated)( IPT_tdstEntryElement *hEntryElement );
ACP_FUNC long (*IPT_fn_lGetAnalogicValue)( IPT_tdstEntryElement *hEntryElement );

ACP_FUNC ACP_tdxBool (*IPT_fn_bIsEntryActionValid)( IPT_tdstEntryElement *hEntryElement );
ACP_FUNC ACP_tdxBool (*IPT_fn_bIsKeyWordValid)( IPT_tdstKeyWordElement *hEntryElement );

ACP_FUNC void (*IPT_fn_vEngineReadInput)(void);