/****************************************************************************
 *
 * SND - Sound Module for CPA
 *
 ****************************************************************************/

#include "SND.h"


SND_tdstSndBankDescriptorList *SND_g_stBankDescriptionList = OFFSET(0x514D50);

long *SND_g_lSoundObjectTypeMenu = OFFSET(0x4FF78C);


long (*SND_fn_lSendRequestSound)( long lIndice, long lType, SND_tduRefEvt uEvt, long lPrio, SND_td_pfn_vSoundCallback pfnProc ) = OFFSET(0x452D20);
