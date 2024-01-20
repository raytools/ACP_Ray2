/****************************************************************************
 *
 * POS - Position module
 *
 ****************************************************************************/

#include "POS.h"


void (*POS_fn_vSetIdentityMatrix)( POS_tdstCompletePosition *p_stMatrix ) = OFFSET(0x4447E0);

void (*POS_fn_vSetRotationMatrix)(
	POS_tdstCompletePosition *hMatrix,
	MTH3D_tdstVector *p_stI,
	MTH3D_tdstVector *p_stJ,
	MTH3D_tdstVector *p_stK
	) = OFFSET(0x445D00);

void (*POS_fn_vTurnMatrixX)( POS_tdstCompletePosition *p_stMatrix, MTH_tdxReal xAngle ) = OFFSET(0x41B1B0);
void (*POS_fn_vTurnMatrixY)( POS_tdstCompletePosition *p_stMatrix, MTH_tdxReal xAngle ) = OFFSET(0x41B2C0);
void (*POS_fn_vTurnMatrixZ)( POS_tdstCompletePosition *p_stMatrix, MTH_tdxReal xAngle ) = OFFSET(0x41B3D0);

void (*POS_fn_vRotatePositionAroundAxis)(
	POS_tdstCompletePosition *hPos,
	MTH3D_tdstVector *p_stAxisVector,
	MTH_tdxReal xAngle
	) = OFFSET(0x4454A0);

void (*POS_fn_vRotatePositionAroundAxisNoTranslation)(
	POS_tdstCompletePosition *hPos,
	MTH3D_tdstVector *p_stAxisVector,
	MTH_tdxReal xAngle
	) = OFFSET(0x445870);

void (*POS_fn_vMulMatrixVector)(
	MTH3D_tdstVector *p_stDest,
	POS_tdstCompletePosition *hMatrix,
	MTH3D_tdstVector *p_stSource
	) = OFFSET(0x4449A0);
