#pragma once

#include "../GLI/GLI_Def.h"
#include "../DNM/DNM.h"
#include "../basedef.h"
#include "../apidef.h"


/****************************************************************************
 *
 * GMT - Game material module
 *
 ****************************************************************************/


typedef long SND_tdxHandleToSoundMaterial;
typedef unsigned short GMT_tdxMask;

typedef struct GMT_tdstGameMaterial GMT_tdstGameMaterial;
typedef struct GMT_tdstCollideMaterial GMT_tdstCollideMaterial;


#define	GMT_C_wZDM (short)0
#define GMT_C_wZDR (short)1
#define GMT_C_wZDE (short)2
#define GMT_C_wZDD (short)3


struct GMT_tdstGameMaterial
{
	GLI_tdstMaterial *hVisualMaterial;
	DNM_tdstMecMatCharacteristics *hMechanicsMaterial;
	SND_tdxHandleToSoundMaterial hSoundMaterial;
	GMT_tdstCollideMaterial *hCollideMaterial;
};

struct GMT_tdstCollideMaterial
{
	short wTypeOfZone;
	GMT_tdxMask xIdentifier;
};