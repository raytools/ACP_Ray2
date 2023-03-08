/****************************************************************************
 * SND - Memory resource types
 ****************************************************************************/

#pragma once

#include "SND_ResBase.h"
#include "SND_Def.h"
#include "LST.h"
#include "basedef.h"


typedef struct SND_tdstMidiMemory
{
	unsigned int ulMidiDeviceId;
	unsigned long ulLength;
	unsigned long ulNbLoops;
}
SND_tdstMidiMemory;

typedef struct SND_tdstMidiStreaming
{
	char szFichier[13];
	unsigned long ulOffset;
	int lLoop;
	int lLast;
}
SND_tdstMidiStreaming;

typedef union SND_tduDataMidi
{
	SND_tdstMidiMemory stMem;
	SND_tdstMidiStreaming stStream;
}
SND_tduDataMidi;


typedef struct SND_tdstInfoTrackMem
{
	LST_M_OptChildDecl(SND_tdstInfoTrackMem, SND_tdstInfoTrackList)
	unsigned long ulFadeIn;
	unsigned long ulFadeOut;
	/*unsigned char ucNbLoops;*/
	unsigned long ulCrossFade;
	SND_tduRefRes uRes;
}
SND_tdstInfoTrackMem;

typedef struct SND_tdstInfoTrackList
{
	LST_M_OptParentDecl(SND_tdstInfoTrackMem)
}
SND_tdstInfoTrackList;


typedef struct SND_tdstSwitchElement
{
	SND_tduRefRes uRes;
	SND_tdxHandleToSoundInfo hIndice;
	LST_M_OptChildDecl(SND_tdstSwitchElement, SND_tdstTypeSwitchMem)
}
SND_tdstSwitchElement;


typedef struct SND_tdstRangeSplitMem
{
	SND_tduRefRes uRes;
	SND_tdxSndReal rPitchA;
	SND_tdxSndReal rPitchB;
	SND_tdxSndReal rPitchC;
	SND_tdxSndReal rPitchD;
	SND_tdxSndReal rCoefPitch;
	unsigned char ucVolume;
	LST_M_OptChildDecl(SND_tdstRangeSplitMem, SND_tdstRangeSplitListMem)
	SND_tdxSndReal rCoefMagAB;
	SND_tdxSndReal rCoefMagCD;
}
SND_tdstRangeSplitMem;

typedef struct SND_tdstRangeSplitListMem
{
	LST_M_OptParentDecl(SND_tdstRangeSplitMem)
}
SND_tdstRangeSplitListMem;

typedef struct SND_tdstRandomElement
{
	SND_tduRefRes uRes;
	SND_tdxSndReal rProb;
	BOOL bCanBeChosenTwice;
	LST_M_OptChildDecl(SND_tdstRandomElement, SND_tdstTypeRandomMem)
}
SND_tdstRandomElement;


/*
 * Types in memory
 */

typedef struct SND_tdstTypeSampleMem
{
	BOOL bPitchable;
	BOOL bVolable;
	BOOL bPanable;
	BOOL bSpacable;
	BOOL bReverbable;
	BOOL bStream;
	BOOL bLoop;
	SND_tduDataSample uData;
	unsigned long ulInc0;
	unsigned long ulFreq;
	unsigned short uwResolution;
	unsigned short uwNbChannels;
	SND_tdeTypeZip eZip;
}
SND_tdstTypeSampleMem;

typedef struct SND_tdstTypeMidiMem
{
	BOOL bStream;
	BOOL bVolable;
	BOOL bLoop;
	unsigned long ulNbLoops;
	unsigned long ulStartLoop;
	unsigned long ulEndLoop;
	SND_tduDataMidi uData;
}
SND_tdstTypeMidiMem;

typedef struct SND_tdstTypeCD
{
	short wTrackId;
	BOOL bVolable;
	BOOL bLoop;
	int lNbLoops;
	unsigned long ulStartLoop;
	unsigned long ulEndLoop;
	unsigned long ulStartingFrame;
	unsigned long ulEndingFrame;
}
SND_tdstTypeCD;

typedef struct SND_tdstTypeSequenceMem
{
	BOOL bLoop;
	unsigned long ulStartLoop;
	unsigned long ulEndLoop;
	unsigned long ulNbLoops;
	unsigned long ulNbElements;
	SND_tdstInfoTrackList stResList;
}
SND_tdstTypeSequenceMem;

typedef struct SND_tdstTypeSwitchMem
{
	LST_M_OptParentDecl(SND_tdstSwitchElement)
	unsigned long ulNbElements;
	long lTypeSwitch;
	SND_tdxHandleToSoundInfo hDefault;
	BOOL bDynamic;
	BOOL bMaintainIfSwitched;
}
SND_tdstTypeSwitchMem;

typedef struct SND_tdstTypeSplitMem
{
	unsigned long ulNbRanges;
	BOOL bStayActive;
	SND_tdstRangeSplitListMem stRangeList;
}
SND_tdstTypeSplitMem;

typedef struct SND_tdstTypeRandomMem
{
	unsigned long ulNbElements;
	SND_tdxSndReal rProbNothing;
	BOOL bNothingCanBeChosenTwice;
	long lLastElementChoosen;
	long lLastResChoosen;
	LST_M_OptParentDecl(SND_tdstRandomElement)
}
SND_tdstTypeRandomMem;
