/****************************************************************************
 *
 * SND Extensions
 *
 ****************************************************************************/

#include "SND_Ext.h"
#include "SND.h"


SND_tdstBlockEvent * SND_fn_p_stFindSndEvent( SND_tdxId xId )
{
	SND_tdstSndBankDescriptorElement *pBankDsc;
	LST_M_DynamicForEach(SND_g_stBankDescriptionList, pBankDsc)
	{
		SND_tdstSndBankPolyEvent *pEventList = &pBankDsc->p_stData->stEventList;
		SND_tdstBlockEvent *pEvent;
		int i;
		LST_M_OptForEach(pEventList, pEvent, i)
		{
			if ( pEvent->Id == xId )
				return pEvent;
		}
	}

	return NULL;
}
