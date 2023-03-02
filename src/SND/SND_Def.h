/****************************************************************************
 * Type definitions for SND module
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "apidef.h"


#define SND_C_UninitializedValue    0x12345678
#define SND_C_EnumAlignment         0x13245678


typedef unsigned long SND_tdxId;
typedef void (CALLBACK *SND_td_pfn_vSoundCallback)( long lParam );


typedef struct SND_tdstSndBankDescriptorElement_ SND_tdstSndBankDescriptorElement;
typedef struct SND_tdstSndBankDescriptorList_ SND_tdstSndBankDescriptorList;

typedef struct SND_tdstBlockEvent_ SND_tdstBlockEvent;
typedef union SND_tduBlockResource_ SND_tduBlockResource;
typedef struct SND_tdstBlockResourceMem_ SND_tdstBlockResourceMem;


typedef union SND_tduRefEvt_
{
	SND_tdxId Id;
	SND_tdstBlockEvent *pstPtr;
}
SND_tduRefEvt;

typedef union SND_tduRefRes_
{
	SND_tdxId Id;
	SND_tdstBlockResourceMem *pstPtr;
}
SND_tduRefRes;


typedef long SND_tdxHandleToSoundInfo;


/*
 * SND "pseudo real" type
 */

typedef long SND_tdxSndReal;
typedef long SND_tdxSndRealTwin; /* two SndReal joined into one 32-bit var: r1r1r2r2 */

#define SND_C_SndReal_1 0x10000
#define SND_C_SndReal_0 0x00000

#define SND_M_SndRealToDouble(r) (((double)(r))/(0x10000))
#define SND_M_DoubleToSndReal(d) ((SND_tdxSndReal)((d)*0x10000))

#define SND_M_SndRealToSndRealTwin(r1, r2) ((SND_tdxSndRealTwin)(((r1) << 8) & 0xFFFF0000) & (((r2) >> 8) & 0xFFFF))

#define SND_M_SndRealTwinToSndReal(rTwin, pr1, pr2)	\
do {												\
	*(pr1) = (((rTwin) >> 16) << 8);				\
	*(pr2) = (((rTwin) << 16) >> 8);				\
} while ( 0 )
