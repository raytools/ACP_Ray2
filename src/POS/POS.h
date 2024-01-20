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
ACP_FUNC void (*POS_fn_vSetRotationMatrix)( POS_tdstCompletePosition *hMatrix, MTH3D_tdstVector *p_stI, MTH3D_tdstVector *p_stJ, MTH3D_tdstVector *p_stK );

ACP_FUNC void (*POS_fn_vTurnMatrixX)( POS_tdstCompletePosition *p_stMatrix, MTH_tdxReal xAngle );
ACP_FUNC void (*POS_fn_vTurnMatrixY)( POS_tdstCompletePosition *p_stMatrix, MTH_tdxReal xAngle );
ACP_FUNC void (*POS_fn_vTurnMatrixZ)( POS_tdstCompletePosition *p_stMatrix, MTH_tdxReal xAngle );

ACP_FUNC void (*POS_fn_vRotatePositionAroundAxis)( POS_tdstCompletePosition *hPos, MTH3D_tdstVector *p_stAxisVector, MTH_tdxReal xAngle );
ACP_FUNC void (*POS_fn_vRotatePositionAroundAxisNoTranslation)( POS_tdstCompletePosition *hPos, MTH3D_tdstVector *p_stAxisVector, MTH_tdxReal xAngle );

ACP_FUNC void (*POS_fn_vMulMatrixVector)( MTH3D_tdstVector *p_stDest, POS_tdstCompletePosition *hMatrix, MTH3D_tdstVector *p_stSource );
