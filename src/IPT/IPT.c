/****************************************************************************
 *
 * IPT - Input module
 *
 ****************************************************************************/

#include "IPT.h"


/* Variables */
IPT_tdstInput *const IPT_g_stInputStructure = OFFSET(0x509E60);
IPT_tdstKeyAndPadDefine *const IPT_gd_hKeyAndPadDefine = OFFSET(0x50A980);

float *const IPT_g_FieldPadGlobalVectorX = OFFSET(0x4b9b68);
float *const IPT_g_FieldPadGlobalVectorY = OFFSET(0x4b9b6c);
float *const IPT_g_FieldPadGlobalVectorZ = OFFSET(0x4b9b70);
float *const IPT_g_FieldPadHorizontalAxis = OFFSET(0x4b9b74);
float *const IPT_g_FieldPadVerticalAxis = OFFSET(0x4b9b76);
float *const IPT_g_FieldPadAnalogForce = OFFSET(0x4b9b78);
float *const IPT_g_FieldPadTrueAnalogForce = OFFSET(0x4b9b7c);
float *const IPT_g_FieldPadRotationAngle = OFFSET(0x4b9b80);
int   *const IPT_g_FieldPadSector = OFFSET(0x4b9b84);

/* Functions */
void (*IPT_fn_vResetInputEntry)( void ) = OFFSET(0x42E090);
void (*IPT_fn_vActualizeHistoric)(void) = OFFSET(0x430880);

ACP_tdxBool (*IPT_fn_bIsJustValidated)( IPT_tdstEntryElement *hEntryElement ) = OFFSET(0x42E850);
ACP_tdxBool (*IPT_fn_bIsJustInvalidated)( IPT_tdstEntryElement *hEntryElement ) = OFFSET(0x42E890);
ACP_tdxBool (*IPT_fn_bIsValidated)( IPT_tdstEntryElement *hEntryElement ) = OFFSET(0x42E870);
ACP_tdxBool (*IPT_fn_bIsInvalidated)( IPT_tdstEntryElement *hEntryElement ) = OFFSET(0x42E8B0);
long (*IPT_fn_lGetAnalogicValue)( IPT_tdstEntryElement *hEntryElement ) = OFFSET(0x42E8D0);

ACP_tdxBool (*IPT_fn_bIsEntryActionValid)( IPT_tdstEntryElement *hEntryElement ) = OFFSET(0x42EAC0);
ACP_tdxBool (*IPT_fn_bIsKeyWordValid)( IPT_tdstKeyWordElement *hEntryElement ) = OFFSET(0x42EAF0);

ACP_FUNC void (*IPT_fn_vEngineReadInput)(void) = OFFSET(0x413890);