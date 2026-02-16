/****************************************************************************
 *
 * SCT - Sector module
 *
 ****************************************************************************/

#include "SCT.h"


void (*SCT_fn_vRemoveObjectInSectorList)( HIE_tdstSuperObject *hCharacter ) = OFFSET(0x412810);
long (*SCT_fn_lSendSectorToViewportStatic)(MTH3D_tdstVector* _p_stAbsolutePositionOfCamera, GLD_tdstViewportAttributes* _p_stVpt, HIE_tdstSuperObject* _hSprObjSector, long _lDrawMask) = OFFSET(0x44af30);
void (*SCT_fn_vSendSectorWhereIAmToViewportWithMirror) (MTH3D_tdstVector* _p_stAbsolutePositionOfCamera, GLD_tdhDevice _hDevice, GLD_tdhViewport _hViewport,
  GLD_tdstViewportAttributes* _p_stVpt, HIE_tdstSuperObject* _hSprObjSector, long _lDrawMask) = OFFSET(0x44b740);