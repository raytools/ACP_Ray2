/****************************************************************************
 *
 * GMT - Game material module
 *
 ****************************************************************************/

#pragma once

#include "GMT_Def.h"
#include "GLI/GLI_Def.h"
#include "DNM/DNM_Def.h"
#include "basedef.h"
#include "apidef.h"


#define	GMT_C_wZDM (short)0
#define GMT_C_wZDR (short)1
#define GMT_C_wZDE (short)2
#define GMT_C_wZDD (short)3


typedef struct GMT_tdstCollideMaterial
{
	short wTypeOfZone;
	GMT_tdxMask xIdentifier;
}
GMT_tdstCollideMaterial;

typedef struct GMT_tdstGameMaterial
{
	GLI_tdstMaterial *hVisualMaterial;
	DNM_tdstMecMatCharacteristics *hMechanicsMaterial;
	SND_tdxHandleToSoundMaterial hSoundMaterial;
	GMT_tdstCollideMaterial *hCollideMaterial;
}
GMT_tdstGameMaterial;


/*
 * Functions
 */

ACP_FUNC GMT_tdstGameMaterial * (*GMT_fn_hCreateGameMaterial)( void );
ACP_FUNC void (*GMT_fn_vSetVisualMaterial)( GMT_tdstGameMaterial *hGameMat, GLI_tdstMaterial *hVisualMat );
