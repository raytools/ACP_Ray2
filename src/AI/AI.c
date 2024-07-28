/****************************************************************************
 *
 * AI - Artificial Intelligence module
 *
 ****************************************************************************/

#include "AI.h"


ACP_tdxBool *const AI_g_bInGameMenu = OFFSET(0x4B9BC8);


AI_tdstNodeInterpret *(*AI_fn_p_stEvalTree)(
	HIE_tdstSuperObject *p_stSpo,
	AI_tdstNodeInterpret *p_stNode,
	AI_tdstGetSetParam *p_stParam
) = OFFSET(0x480B90);

void (*AI_fn_vReinitAI)( AI_tdstMind *p_stMind ) = OFFSET(0x466D00);

void (*AI_fn_vBrainAlloc)( HIE_tdstEngineObject *p_stObject ) = OFFSET(0x417E10);


/* ultra operator */

void (*AI_fn_vGetUltraOperatorPerso)(
	unsigned char bYouHaveRightToUseThisFunction,
	HIE_tdstSuperObject *hCurrentSuperObjPerso,
	HIE_tdstSuperObject **hNewSuperObjPerso
) = OFFSET(0x4825B0);

unsigned char (*AI_fn_ucGetProcedureUltraOperator)( AI_tdeProcedureId eProcId ) = OFFSET(0x482680);
