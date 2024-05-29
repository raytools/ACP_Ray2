/****************************************************************************
 * 
 * AGO - Animations Graphiques Optimisées
 *
 ****************************************************************************/

#pragma once

#include "GLI/GLD.h"
#include "MTH.h"


/* Part behavior */
#define AGO_TYPEMASK			0x000000FF
#define AGO_STILL				0x00000000
#define AGO_FALLING				0x00000001
#define AGO_SINUSING			0x00000002
#define AGO_MOVING				0x00000003
#define AGO_GEISER				0x00000004
#define AGO_FALLING_SLOW		0x00000005
#define AGO_ROTATING_SLOW		0x00000006
#define AGO_MOVINGSINXY			0x00000007
#define AGO_SPIRALE				0x00000008
#define AGO_MOVING_AND_SLOWING	0x00000009
#define AGO_GOINGTO				0x0000000A
#define AGO_MOVINGSINXYUP		0x0000000B
#define AGO_2DSPIRALE			0x0000000C
#define AGO_FASEGOINGTO			0x0000000E
#define AGO_FIREWORKS			0x0000000F
#define AGO_FALLING_MEGAFAST	0x00000010
#define AGO_FRAME				0x00000011
#define AGO_GOTO				0x00000012

/* Scaling Behavior */
#define AGO_SCALEMASK			0x00000F00
#define AGO_SCALING_SLOW		0x00000100
#define AGO_SCALING_MID			0x00000200
#define AGO_SCALING_FAST		0x00000300
#define AGO_SCALING_FASTEST		0x00000400
#define AGO_UNSCALING_FAST		0x00000500
#define AGO_UNSCALING_SLOW		0x00000600
#define AGO_UNSCALING_FASTEST	0x00000700
#define AGO_SCALING_MEGASLOW	0x00000800
#define AGO_SCALING_MEGAFASTY	0x00000900
#define AGO_SCALING_XTOY		0x00000A00
#define AGO_SCALING_YTOX		0x00000B00
#define AGO_SCALING_YTOX2		0x00000D00
#define AGO_BIG_RANDOM_SCALE	0x00000E00
#define AGO_SMALL_RANDOM_SCALE	0x00000F00

/* Shading Behavior */
#define AGO_SHADEMASK			0x0000F000
#define AGO_SHADE_SLOW			0x00001000
#define AGO_SHADE_MID 			0x00002000
#define AGO_SHADE_FAST			0x00003000
#define AGO_SHADE_FASTEST		0x00004000
#define AGO_SHADE_MEGAFAST		0x00005000
#define AGO_SHADE_TWOFRAMES		0x00006000
#define AGO_APPEAR				0x00007000
#define AGO_WAIT				0x00008000
#define AGO_RANDOM_SHADE		0x00009000
#define AGO_UNSHADE				0x0000A000

/* Part death & misc flags */
#define AGO_TIMELIMITED			0x00010000
#define AGO_ENDASPLOUF			0x00020000
#define AGO_ZLIMITED			0x00040000
#define AGO_ZELDA				0x00080000
#define AGO_MUSTDIE				0x01000000
#define AGO_FOLLOWZ				0x02000000
#define AGO_LOOPANIM			0x04000000
#define AGO_BASEDSCALE			0x08000000


#define AGO_GEOMETRY_TYPE_MASK	0xF0000000
#define AGO_XYPLAN				0x10000000
#define AGO_ORTHOPLAN			0x20000000
#define AGO_ORIENTEDXYPLAN		0x30000000
#define AGO_REMANANCE			0x40000000
#define AGO_REMANANCE2			0x50000000
#define AGO_REMANANCE3			0x60000000

/*
 * Functions
 */

ACP_FUNC void (*AGO_vDisplayGAUGES)( GLD_tdstViewportAttributes *p_stVpt );

ACP_FUNC void (*AGO_vAddParticle)( unsigned long PartType, MTH3D_tdstVector *p_stPosition, MTH3D_tdstVector *p_stDirection, void *hVisualMaterial, float parameter );
ACP_FUNC /* AGO_Part */ void * (*AGO_vCreatePart)( unsigned long parm_ulType, float *parm_a3_fPosition, float *parm_a3_fDirection, float TimeLimit, float fScaleX, float fScaleY, void *pVisualMaterial );
ACP_FUNC void (*AGO_vCreateTriangle)( float c1[3], float c2[3], float c3[3], void *VisualMat, float U1, float V1, float U2, float V2, float U3, float V3, float DelayTime, unsigned long Parameter );
