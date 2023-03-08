/****************************************************************************
 * SND - Resource
 ****************************************************************************/

#pragma once

#include "SND_Theme.h"
#include "SND_ResMem.h"
#include "SND_Def.h"
#include "LST.h"
#include "basedef.h"


#define SND_C_NbTypeResource 12

typedef enum SND_tdeTypeResource
{
	SND_E_TR_Invalid,
	SND_E_TR_Sample,
	SND_E_TR_Midi,
	SND_E_TR_CdAudio,
	SND_E_TR_Sequence,
	SND_E_TR_Switch_Old,
	SND_E_TR_Split,
	SND_E_TR_Theme_Old,
	SND_E_TR_Switch,
	SND_E_TR_Theme_Old2,
	SND_E_TR_Random,
	SND_E_TR_Theme,
	SND_E_TR_ForAlignment = SND_C_EnumAlignment
}
SND_tdeTypeResource;

typedef enum SND_tdeTypeStorage
{
	SND_E_TS_External,
	SND_E_TS_Megafile,
	SND_E_TS_Bigfile,
	SND_E_TS_ForAlignment = SND_C_EnumAlignment
}
SND_tdeTypeStorage;

typedef union SND_tduResMem
{
	SND_tdstTypeSampleMem stSample;
	SND_tdstTypeMidiMem stMidi;
	SND_tdstTypeCD stCD;
	SND_tdstTypeSequenceMem stSequence;
	SND_tdstTypeSwitchMem stSwitch;
	SND_tdstTypeSplitMem stSplit;
	SND_tdstTypeThemeMem stTheme;
	SND_tdstTypeRandomMem stRandom;
}
SND_tduResMem;

typedef union SND_tduResDisk
{
	/* TODO
	tdstTypeSampleDisk stSample;
	tdstTypeMidiDisk stMidi;
	tdstTypeCD stCD;
	tdstTypeSequenceDisk stSequence;
	tdstTypeSwitchDisk stSwitch;
	tdstTypeSwitchOld stSwitchOld;
	tdstTypeSplitDisk stSplit;
	tdstTypeThemeDisk stTheme;
	tdstTypeRandomDisk stRandom;
	tdstTypeThemeOld stThemeOld;
	tdstTypeThemeDiskOld2 stThemeOld2;
	*/
	void *dummy;
}
SND_tduResDisk;


typedef struct SND_tdstSndPolyResource
{
	LST_M_OptParentDecl(SND_tdstBlockResourceMem)
}
SND_tdstSndPolyResource;

typedef struct SND_tdstBlockResourceMem
{
	SND_tdxId Id;
	SND_tdeTypeResource eType;
	SND_tdeTypeStorage eStorage;
	unsigned char ucVolume;
	BOOL bIsLoaded;
	SND_tduResMem uRes;
	LST_M_OptChildDecl(SND_tdstBlockResourceMem, SND_tdstSndPolyResource)
}
SND_tdstBlockResourceMem;

typedef struct SND_tdstBlockResourceDisk
{
	SND_tdxId Id;
	SND_tdeTypeResource eType;
	SND_tdeTypeStorage eStorage;
	unsigned long ulDataSize;
	unsigned long ulDataOffset;
	unsigned char ucVolume;
	SND_tduResDisk uRes;
}
SND_tdstBlockResourceDisk;

typedef union SND_tduBlockResource
{
	SND_tdstBlockResourceMem stMem;
	SND_tdstBlockResourceDisk stDisk;
}
SND_tduBlockResource;
