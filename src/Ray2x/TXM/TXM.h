/****************************************************************************
 *
 * TXM - Texture Manager module
 *
 ****************************************************************************/

#pragma once

#include "GLI/GLI_Def.h"
#include "basedef.h"
#include "Ray2x/apidefx.h"


/* initialise the module */
ACPX_API void TXM_fn_vInit( void );

/* acquire TXM texture handle from GF file
   NOTE: texture name should end in .tga or .bmp, depending on the original file! */
ACPX_API GLI_tdstTexture * TXM_fn_hLoadTextureGF( char const *szGFName );

/* release TXM texture handle */
ACPX_API BOOL TXM_fn_bUnLoadTexture( GLI_tdstTexture const *hTexture );
