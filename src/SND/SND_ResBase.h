/****************************************************************************
 * SND - Resource base
 ****************************************************************************/

#pragma once

#include "SND_Def.h"
#include "basedef.h"


typedef enum SND_tdeTypeZip
{
	SND_SAMPLE_Invalid,
	SND_SAMPLE_PCM,
	SND_SAMPLE_MPEG,
	SND_SAMPLE_AIFF,
	SND_SAMPLE_ADPCM,
	SND_SAMPLE_ADPCM_ToConvert,
	SND_SAMPLE_ForAlignment = SND_C_EnumAlignment
}
SND_tdeTypeZip;


typedef struct SND_tdstSampleMemory
{
	void *pvPtrFirst;
	unsigned long ulNbEchLoop;
	unsigned long ulNbEch;
}
SND_tdstSampleMemory;

typedef struct SND_tdstSampleStreaming
{
	char szFileName[13];
	unsigned long ulOffsetFirst;
	unsigned long ulOffsetLoop;
	unsigned long ulOffsetLast;
}
SND_tdstSampleStreaming;

typedef union SND_tduDataSample
{
	SND_tdstSampleMemory stMem;
	SND_tdstSampleStreaming stStream;
}
SND_tduDataSample;
