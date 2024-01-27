/****************************************************************************
 *
 * MTH - Common Mathematic Library
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"


#define MTH_C_Pi			(float)3.141592653589793
#define MTH_C_2Pi			(float)6.283185307179586
#define MTH_C_PiBy2			(float)1.570796326794896


typedef float MTH_tdxReal;

typedef struct MTH2D_tdstVector MTH2D_tdstVector;
typedef struct MTH3D_tdstVector MTH3D_tdstVector;
typedef struct MTH4D_tdstVector MTH4D_tdstVector;

typedef struct MTH2D_tdstMatrix MTH2D_tdstMatrix;
typedef struct MTH3D_tdstMatrix MTH3D_tdstMatrix;
typedef struct MTH4D_tdstMatrix MTH4D_tdstMatrix;

typedef struct MTH_tdstRotation MTH_tdstRotation;
typedef struct MTH_tdstMove MTH_tdstMove;

/* Use 3D structs as default */

typedef MTH3D_tdstVector MTH_tdstVector;
typedef MTH3D_tdstMatrix MTH_tdstMatrix;


/****************************************************************************
 * 2D math
 ****************************************************************************/

struct MTH2D_tdstVector
{
	MTH_tdxReal x;
	MTH_tdxReal y;
};

struct MTH2D_tdstMatrix
{
	MTH2D_tdstVector stCol_0;
	MTH2D_tdstVector stCol_1;
};


/****************************************************************************
 * 3D math
 ****************************************************************************/

struct MTH3D_tdstVector
{
	MTH_tdxReal x;
	MTH_tdxReal y;
	MTH_tdxReal z;
};

struct MTH3D_tdstMatrix
{
	MTH3D_tdstVector stCol_0;
	MTH3D_tdstVector stCol_1;
	MTH3D_tdstVector stCol_2;
};

struct MTH_tdstRotation
{
	MTH_tdxReal xAngle;
	MTH3D_tdstVector stAxis;
};

struct MTH_tdstMove
{
	MTH3D_tdstVector stLinear;
	MTH_tdstRotation stAngular;
};


#define MTH3D_M_vAddVector( VectDest, VectA, VectB )	\
{														\
	(VectDest)->x = (VectA)->x + (VectB)->x;			\
	(VectDest)->y = (VectA)->y + (VectB)->y;			\
	(VectDest)->z = (VectA)->z + (VectB)->z;			\
}

#define MTH3D_M_vSubVector( VectDest, VectA, VectB )	\
{														\
	(VectDest)->x = (VectA)->x - (VectB)->x;			\
	(VectDest)->y = (VectA)->y - (VectB)->y;			\
	(VectDest)->z = (VectA)->z - (VectB)->z;			\
}

#define MTH3D_M_vMulVectorScalar( VectDest, VectA, xB )	\
{														\
	(VectDest)->x = (VectA)->x * ((MTH_tdxReal)xB);		\
	(VectDest)->y = (VectA)->y * ((MTH_tdxReal)xB);		\
	(VectDest)->z = (VectA)->z * ((MTH_tdxReal)xB);		\
}

#define MTH3D_M_vDivVectorScalar( VectDest, VectA, xB )	\
{														\
	(VectDest)->x = (VectA)->x / ((MTH_tdxReal)xB);		\
	(VectDest)->y = (VectA)->y / ((MTH_tdxReal)xB);		\
	(VectDest)->z = (VectA)->z / ((MTH_tdxReal)xB);		\
}

#define MTH3D_M_vScaleVector( VectDest, VectA, VectB )	\
{														\
	(VectDest)->x = (VectA)->x * (VectB)->x;			\
	(VectDest)->y = (VectA)->y * (VectB)->y;			\
	(VectDest)->z = (VectA)->z * (VectB)->z;			\
}

#define MTH3D_M_vInvVector( VectDest, VectA )			\
{														\
	(VectDest)->x = -(VectA)->x;						\
	(VectDest)->y = -(VectA)->y;						\
	(VectDest)->z = -(VectA)->z;						\
}

#define MTH3D_M_xDotProductVector( VectA, VectB )		\
	( ((VectA)->x * (VectB)->x)							\
	+ ((VectA)->y * (VectB)->y)							\
	+ ((VectA)->z * (VectB)->z) )

#define MTH3D_M_xSqrNormVector( VectA )					\
	MTH3D_M_xDotProductVector(VectA, VectA)

#define MTH3D_M_xNormVector( VectA )					\
	sqrtf(MTH3D_M_xSqrNormVector(VectA))

#define MTH3D_M_xInvNormVector( VectA )					\
	(1.0f/MTH3D_M_xNormVector(VectA))

#define MTH3D_M_vNormalizeVector( VectDest, VectA )				\
{																\
	MTH_tdxReal __xInvNorm = MTH3D_M_xInvNormVector(VectA);		\
	MTH3D_M_vMulVectorScalar(VectDest, VectA, __xInvNorm);		\
}


/****************************************************************************
 * 4D math
 ****************************************************************************/

struct MTH4D_tdstVector
{
	MTH_tdxReal x;
	MTH_tdxReal y;
	MTH_tdxReal z;
	MTH_tdxReal w;
};

struct MTH4D_tdstMatrix
{
	MTH4D_tdstVector stCol_0;
	MTH4D_tdstVector stCol_1;
	MTH4D_tdstVector stCol_2;
	MTH4D_tdstVector stCol_3;
};
