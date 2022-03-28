/****************************************************************************
 *
 * POS - Position module
 *
 ****************************************************************************/

#pragma once

#include "MTH.h"
#include "apidef.h"


typedef enum MTH_tdeMatrixType
{
	MTH_C_Type_IdentityMatrix		= 1,
	MTH_C_Type_TranslationMatrix	= 2,
	MTH_C_Type_RotationMatrix		= 3,
	MTH_C_Type_CompleteMatrix		= 4
}
MTH_tdeMatrixType;

typedef struct POS_tdstCompletePosition
{
	MTH_tdeMatrixType eType;

	MTH3D_tdstVector stPos;

	MTH3D_tdstMatrix stRotationMatrix;
	MTH3D_tdstMatrix stTransformMatrix;
}
POS_tdstCompletePosition;


/*
 * Functions
 */

ACP_FUNC void (*POS_fn_vSetIdentityMatrix)( POS_tdstCompletePosition *p_stMatrix );
