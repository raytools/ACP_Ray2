/****************************************************************************
 *
 * AI Extensions
 *
 ****************************************************************************/

#include "AI_Ext.h"
#include "AI_Array.h"
#include "HIE/HIE.h"


BOOL AI_fn_bGetDsgVar( HIE_tdstSuperObject *p_stSuperObj, unsigned char ucDsgVarId, AI_tdeDsgVarType *p_eType_Out, void **p_pValue_Out )
{
	if ( !HIE_M_bSuperObjectIsActor(p_stSuperObj) )
		return FALSE;

	AI_tdstMind *hMind = AI_M_hGetMindOfSuperObj(p_stSuperObj);

	if ( ucDsgVarId > AI_M_ucGetNbDsgVar(hMind) )
		return FALSE;

	AI_tdstDsgVarInfo *p_stDsgInfo = AI_M_p_stGetDsgVarInfo(hMind, ucDsgVarId);

	if ( p_eType_Out )
		*p_eType_Out = p_stDsgInfo->eTypeId;
	if ( p_pValue_Out )
		*p_pValue_Out = AI_M_p_cGetDsgMemBuffer(hMind) + p_stDsgInfo->ulOffsetInDsgMem;

	return TRUE;
}

ACP_tdxBool AI_fn_bGetBooleanInArray( HIE_tdstSuperObject *p_stSuperObj, unsigned char ucDsgVarId, unsigned int ulIndex )
{
	AI_tdstArray *p_stArray;
	AI_fn_bGetDsgVar(p_stSuperObj, ucDsgVarId, NULL, &p_stArray);

	ulIndex--;
	unsigned long ulIndexFirstLong = (ulIndex >> 5);
	unsigned long ulIndexFirstBit = (ulIndex & 31);

	return (AI_M_pArrayElement(p_stArray, ulIndexFirstLong)->lValue & (1 << ulIndexFirstBit)) ? TRUE : FALSE;
}
