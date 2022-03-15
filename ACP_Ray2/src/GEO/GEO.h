#pragma once

#include "../basedef.h"
#include "../apidef.h"


/****************************************************************************
 *
 * GEO - Common Geometry module
 *
 ****************************************************************************/


typedef float GEO_tdxColorValue;
typedef struct GEO_tdstColor GEO_tdstColor;


struct GEO_tdstColor
{
	GEO_tdxColorValue xR;
	GEO_tdxColorValue xG;
	GEO_tdxColorValue xB;
	GEO_tdxColorValue xA;
};
