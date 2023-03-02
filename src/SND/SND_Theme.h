/****************************************************************************
 * SND - Theme resource
 ****************************************************************************/

#pragma once

#include "SND_ResBase.h"
#include "SND_Def.h"
#include "LST.h"
#include "basedef.h"


#define SND_C_Theme_NoLoop -1
#define SND_C_Theme_PartPlayOnce 0
#define SND_C_Theme_MainLoopInfinite 0
#define SND_C_Theme_NoPartOutro -1


typedef enum SND_tdeTypeTransition_
{
	SND_E_Transition_Crossfade,
	SND_E_Transition_AtEndOfPart,
	SND_E_Transition_Outro,
	SND_E_Transition_ForAlignment = SND_C_EnumAlignment
} SND_tdeTypeTransition;

typedef struct SND_tdstThemePart_
{
	SND_tduRefRes uRes;
	BOOL bLoopStart;
	BOOL bLoopEnd;
	long lNbLoops;
	SND_tdeTypeTransition eTransition;
	SND_tdxSndReal rFadeDuration;
	LST_M_OptChildDecl(SND_tdstThemePart, SND_tdstTypeThemeMem)
}
SND_tdstThemePart;

typedef struct SND_tdstThemePartOutro_
{
	SND_tduRefRes uRes;
	SND_tdeTypeTransition eTransition;
	SND_tdxSndReal rFadeDuration;
}
SND_tdstThemePartOutro;


typedef struct SND_tdstTypeThemeDisk_
{
	unsigned long ulStartLoop;
	unsigned long ulEndLoopObsolete;
	unsigned long ulNbLoops;
	unsigned long ulNbParts;
	long lOffsetPartOutro;
	SND_tdxSndReal rFadeDuration;
	LST_M_OptParentDecl(SND_tdstThemePart)
}
SND_tdstTypeThemeDisk;

typedef struct SND_tdstTypeThemeMem_
{
	unsigned long ulStartLoop;
	unsigned long ulEndLoopObsolete;
	unsigned long ulNbParts;
	SND_tdstThemePartOutro *pstPartOutro;
	SND_tdxSndReal rFadeDuration;
	unsigned long ulNbLoops;
	LST_M_OptParentDecl(SND_tdstThemePart)
}
SND_tdstTypeThemeMem;
