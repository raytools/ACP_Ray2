/****************************************************************************
 *
 * AI Extensions
 *
 ****************************************************************************/

#pragma once

#include "AI.h"
#include "HIE/HIE_Def.h"
#include "HIE/HIE_Ext.h"
#include "basedef.h"
#include "apidef.h"


/****************************************************************************
 * Convenience macros
 ****************************************************************************/

#define AI_M_hGetMindOfActor( hActor ) ((hActor)->hBrain->p_stMind)
#define AI_M_hGetMindOfSuperObj( hSuperObj ) (HIE_M_hSuperObjectGetActor(hSuperObj)->hBrain->p_stMind)

#define AI_M_p_stGetDsgMem( hMind ) ((hMind)->p_stDsgMem)
#define AI_M_p_stGetDsgVarStruct( hMind ) (*(AI_M_p_stGetDsgMem(hMind)->pp_stDsgVar))
#define AI_M_ucGetNbDsgVar( hMind ) (AI_M_p_stGetDsgVarStruct(hMind)->ucNbDsgVar)

#define AI_M_p_cGetDsgMemBuffer( hMind ) (AI_M_p_stGetDsgMem(hMind)->p_cDsgMemBuffer)
#define AI_M_p_cGetDsgMemBufferInit( hMind ) (AI_M_p_stGetDsgMem(hMind)->p_cDsgMemBufferInit)
#define AI_M_p_cGetDsgMemDefaultInit( hMind ) (AI_M_p_stGetDsgVarStruct(hMind)->p_cDsgMemDefaultInit)

#define AI_M_p_stGetDsgVarInfo( hMind, ucId ) (&(AI_M_p_stGetDsgVarStruct(hMind)->a_stDsgVarInfo[(ucId)]))
#define AI_M_eGetDsgVarType( hMind, ucId ) (AI_M_p_stGetDsgVarInfo(hMind,ucId)->eTypeId)
#define AI_M_ulGetDsgVarOffset( hMind, ucId ) (AI_M_p_stGetDsgVarInfo(hMind,ucId)->ulOffsetInDsgMem)
#define AI_M_ulGetDsgVarAddr( hMind, ucId ) (AI_M_p_cGetDsgMemBuffer(hMind)+AI_M_ulGetDsgVarOffset(hMind,ucId))

/****************************************************************************/


ACP_API BOOL AI_fn_bGetDsgVar( HIE_tdstSuperObject *p_stSuperObj, unsigned char ucDsgVarId, AI_tdeDsgVarType *p_eType_Out, void **p_pValue_Out );
ACP_API ACP_tdxBool AI_fn_bGetBooleanInArray( HIE_tdstSuperObject *p_stSuperObj, unsigned char ucDsgVarId, unsigned int ulIndex );
