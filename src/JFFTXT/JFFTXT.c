/****************************************************************************
 *
 * JFFTXT - 2D Text Module
 *
 ****************************************************************************/

#include "JFFTXT.h"


void (*JFFTXT_vAffiche)( void *pContext ) = OFFSET(0x465C10);
void (*JFFTXT_vDrawString)( void *pContext, JFFTXT_tdstString *p_stString ) = OFFSET(0x4660B0);

void (*JFFTXT_vAddText)( unsigned long ulTextId, MTH3D_tdstVector *p_stPos, char *szText, float xAlpha ) = OFFSET(0x465A50);
void (*JFFTXT_vExtendText)( unsigned long ulTextId, JFFTXT_tdeExtendParam ulParamToChange, float xNewValue ) = OFFSET(0x465AA0);
void (*JFFTXT_vGetStringExtents)( JFFTXT_tdstString *p_stString, MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight ) = OFFSET(0x465E30);

void (*JFFTXT_vGetSizeValues)( float xSize, long *dx, long *dy, long *cx, long *cy ) = OFFSET(0x465DD0);
long (*JFFTXT_lGetStringLength)( unsigned char *pText, long dx ) = OFFSET(0x465D60);
