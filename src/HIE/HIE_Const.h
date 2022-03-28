/****************************************************************************
 * Constant values for HIE module
 ****************************************************************************/

#pragma once


typedef enum HIE_tdeSpoFlags
{
	HIE_C_Flag_NotPickable				= 1 << 0,
	HIE_C_Flag_Hidden					= 1 << 1,
	HIE_C_Flag_NoTransformationMatrix	= 1 << 2,
	HIE_C_Flag_ZoomInsteadOfScale		= 1 << 3,
	HIE_C_Flag_TypeOfBoundingVolume		= 1 << 4,
	HIE_C_Flag_Superimposed				= 1 << 5,
	HIE_C_Flag_NotHitByRayTrace			= 1 << 6,
	HIE_C_Flag_NoShadowOnMe				= 1 << 7,
	HIE_C_Flag_SemiLookAt				= 1 << 8,
	HIE_C_Flag_CheckChildren			= 1 << 9,
	HIE_C_Flag_MagnetModification		= 1 << 15,
	HIE_C_Flag_ModuleTransparency		= 1 << 16,
	HIE_C_Flag_ExcluLight				= 1 << 17,
	HIE_C_Flag_SuperimposedClipping		= 1 << 18,
	HIE_C_Flag_OutlineMode				= 1 << 19
}
HIE_tdeSpoFlags;

typedef enum HIE_tdeTypeOfObject
{
	HIE_C_Type_Unknown					= 0x0,
	HIE_C_Type_SuperObject				= 0x1,
	HIE_C_Type_Actor					= 0x2,
	HIE_C_Type_Sector					= 0x4,
	HIE_C_Type_PO						= 0x8,
	HIE_C_Type_PO_Mirror				= 0x10,
	HIE_C_Type_IPO						= 0x20,
	HIE_C_Type_IPO_Mirror				= 0x40,
	HIE_C_Type_SpecialEffect			= 0x80,
	HIE_C_Type_NoAction					= 0x100,
	HIE_C_Type_Mirror					= 0x200,
	HIE_C_Type_EDT_Geometric			= 0x400,
	HIE_C_Type_EDT_Light				= 0x800,
	HIE_C_Type_EDT_Waypoint				= 0x1000,
	HIE_C_Type_EDT_ZdD					= 0x2000,
	HIE_C_Type_EDT_ZdE					= 0x4000,
	HIE_C_Type_EDT_ZdM					= 0x8000,
	HIE_C_Type_EDT_ZdR					= 0x10000,
	HIE_C_Type_EDT_BdV					= 0x20000,
	HIE_C_Type_EDT_TestPoint			= 0x40000
}
HIE_tdeTypeOfObject;
