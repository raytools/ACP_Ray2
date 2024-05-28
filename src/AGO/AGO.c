/****************************************************************************
 * 
 * AGO - Animations Graphiques Optimisées
 *
 ****************************************************************************/

#include "AGO.h"


void (*AGO_vDisplayGAUGES)( GLD_tdstViewportAttributes *p_stVpt ) 
	= OFFSET(0x460670);
void (*AGO_vAddParticle)(unsigned long PartType, MTH3D_tdstVector* p_stPosition, MTH3D_tdstVector* p_stDirection, void* hVisualMaterial, float parameter)
	= OFFSET(0x463390);
ACP_FUNC int* (*AGO_vCreatePart)(unsigned long parm_ulType, float* parm_a3_fPosition, float* parm_a3_fDirection, float TimeLimit, float fScaleX, float fScaleY, void* pVisualMaterial)
	= OFFSET(0x4600C0);
ACP_FUNC void (*AGO_vCreateTriangle)(float c1[3], float c2[3], float c3[3], void* VisualMat, float U1, float V1, float U2, float V2, float U3, float V3, float DelayTime, unsigned long Parameter)
	= OFFSET(0x466530);