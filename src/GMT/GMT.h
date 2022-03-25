/****************************************************************************
 *
 * GMT - Game material module
 *
 ****************************************************************************/

#pragma once

#include "GLI/GLI_Def.h"
#include "DNM/DNM_Def.h"
#include "basedef.h"
#include "apidef.h"


#define	GMT_C_wZDM (short)0
#define GMT_C_wZDR (short)1
#define GMT_C_wZDE (short)2
#define GMT_C_wZDD (short)3

typedef long SND_tdxHandleToSoundMaterial;
typedef unsigned short GMT_tdxMask;


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
