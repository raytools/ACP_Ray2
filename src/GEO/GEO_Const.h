/****************************************************************************
 * Constant values for GEO module
 ****************************************************************************/

#pragma once


 /* Constant for no element parallel boxes */
#define GEO_C_xNoParallelBox ((ACP_tdxIndex)-1)

 /* memory channels */
#define GEO_C_FixMemoryChannel 1
#define GEO_C_LevelMemoryChannel 2


/* reference objects */

#define GEO_C_lNbLatitudes		8
#define GEO_C_lNbLongitudes		8
#define GEO_C_lNbConeEdges		6

#define GEO_C_lNbTrianglesInSphere	((GEO_C_lNbLongitudes * 2) + (GEO_C_lNbLongitudes) * 2 * (GEO_C_lNbLatitudes - 3))
#define GEO_C_lNbPointsInSphere		(GEO_C_lNbLongitudes * (GEO_C_lNbLatitudes - 2) + 2)
