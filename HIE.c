#include "apidef.h"
#include "HIE.h"


///////////////////////////
//
// HIE - Object Hierarchy
// 
///////////////////////////


ACP_API void (*HIE_fn_vChangeFather)(HIE_tdstSuperObject *p_stSpo, HIE_tdstSuperObject *p_stNewFather, BYTE bFirstChild) = 0x45C080;
