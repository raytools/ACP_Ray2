#pragma once

#include "basedef.h"


//////////////////////
//
// MTH - Math Module
//
//////////////////////


typedef float MTH_tdxReal;

typedef struct MTH2D_tdstVector MTH2D_tdstVector;
typedef struct MTH3D_tdstVector MTH3D_tdstVector;
typedef struct MTH4D_tdstVector MTH4D_tdstVector;

typedef struct MTH2D_tdstMatrix MTH2D_tdstMatrix;
typedef struct MTH3D_tdstMatrix MTH3D_tdstMatrix;
typedef struct MTH4D_tdstMatrix MTH4D_tdstMatrix;

typedef struct MTH_tdstTransformation MTH_tdstTransformation;
typedef struct MTH_tdstRotation MTH_tdstRotation;
typedef struct MTH_tdstMove MTH_tdstMove;

// Use 3D structs as default

typedef MTH3D_tdstVector MTH_tdstVector;
typedef MTH3D_tdstMatrix MTH_tdstMatrix;


////////////
// 2D Math
////////////

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


////////////
// 3D Math
////////////

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

struct MTH_tdstTransformation
{
	int eType;
	MTH3D_tdstVector stPos;

	MTH3D_tdstMatrix stTransformMatrix;
	MTH3D_tdstMatrix stScaleMatrix;
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


////////////
// 4D Math
////////////

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
