/****************************************************************************
 *
 * SND - Sound Module for CPA
 *
 ****************************************************************************/

#pragma once

#include "SND_Def.h"
#include "SND_Event.h"
#include "SND_Resource.h"

#include "LST.h"
#include "MTH.h"
#include "basedef.h"
#include "apidef.h"


typedef enum SND_tdeBankState
{
	SND_BANK_NotLoaded,
	SND_BANK_Loaded,
	SND_BANK_Loading,
	SND_BANK_Waiting,
	SND_BANK_ToBeLoaded,
	SND_BANK_ForAlignment = SND_C_EnumAlignment
}
SND_tdeBankState;


typedef struct SND_tdstSndBankHeader
{
	long lVersion;
}
SND_tdstSndBankHeader;

typedef struct SND_tdstSndBankPolyEvent
{
	LST_M_OptParentDecl(SND_tdstBlockEvent)
}
SND_tdstSndBankPolyEvent;

typedef struct SND_tdstSndBankPolyRes
{
	LST_M_OptParentDecl(SND_tduBlockResource)
}
SND_tdstSndBankPolyRes;

typedef struct SND_tdstSndBankHead
{
	SND_tdstSndBankHeader stHeader;
	SND_tdstSndBankPolyEvent stEventList;
	SND_tdstSndBankPolyRes stResList;
	unsigned long ulOffsetMPEG;
	unsigned long ulOffsetMidi;
	unsigned long ulOffsetSample;
	unsigned long ulOffsetADPCM;
	unsigned long ulOffsetStreaming;
	unsigned long ulTotalSize;
}
SND_tdstSndBankHead;


typedef struct SND_tdstSndBankDescriptorElement
{
	int _gap_00;
	int lId;
	unsigned long ulLevel;
	char szFileName[13];
	long lBNMCheckVersion;
	SND_tdeBankState eState;
	SND_tdstSndBankHead *p_stData;
	void *pDataPrimary;
	void *pDataMPEG;
	void *pDataMidi;
	void *pDataSample;
	void *pDataADPCM;
	LST_M_DynamicChildDecl(SND_tdstSndBankDescriptorElement, SND_tdstSndBankDescriptorList)
}
SND_tdstSndBankDescriptorElement;

typedef struct SND_tdstSndBankDescriptorList
{
	LST_M_DynamicParentDecl(SND_tdstSndBankDescriptorElement)
}
SND_tdstSndBankDescriptorList;


/*
 * Variables
 */

ACP_VAR SND_tdstSndBankDescriptorList *const SND_g_stBankDescriptionList;

ACP_VAR long *const SND_g_lSoundObjectTypeMenu;


/*
 * Functions
 */

ACP_FUNC long (*SND_fn_lSendRequestSound)( long lIndice, long lType, SND_tduRefEvt uEvt, long lPrio, SND_td_pfn_vSoundCallback pfnProc );
