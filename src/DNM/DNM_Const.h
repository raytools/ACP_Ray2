/****************************************************************************
 * Constant values for DNM module
 ****************************************************************************/

#pragma once


/* Dynamics Flags */
#define DNM_C_Flag_Animation					0x00000001
#define DNM_C_Flag_Collide						0x00000002
#define DNM_C_Flag_Gravity						0x00000004
#define DNM_C_Flag_Tilt							0x00000008
#define DNM_C_Flag_Gi							0x00000010
#define DNM_C_Flag_OnGround						0x00000020
#define DNM_C_Flag_Climb						0x00000040
#define DNM_C_Flag_CollisionControl				0x00000080
#define DNM_C_Flag_KeepWallSpeedZ				0x00000100
#define DNM_C_Flag_SpeedLimit					0x00000200
#define DNM_C_Flag_Inertia						0x00000400
#define DNM_C_Flag_Stream						0x00000800
#define DNM_C_Flag_StickOnPlatform				0x00001000
#define DNM_C_Flag_Scale						0x00002000
#define DNM_C_Flag_AbsoluteImposeSpeed			0x00004000
#define DNM_C_Flag_AbsoluteProposeSpeed			0x00008000
#define DNM_C_Flag_AbsoluteAddSpeed				0x00010000
#define DNM_C_Flag_ImposeSpeedX					0x00020000
#define DNM_C_Flag_ImposeSpeedY					0x00040000
#define DNM_C_Flag_ImposeSpeedZ					0x00080000
#define DNM_C_Flag_ProposeSpeedX				0x00100000
#define DNM_C_Flag_ProposeSpeedY				0x00200000
#define DNM_C_Flag_ProposeSpeedZ				0x00400000
#define DNM_C_Flag_AddSpeedX					0x00800000
#define DNM_C_Flag_AddSpeedY					0x01000000
#define DNM_C_Flag_AddSpeedZ					0x02000000
#define DNM_C_Flag_LimitX						0x04000000
#define DNM_C_Flag_LimitY						0x08000000
#define DNM_C_Flag_LimitZ						0x10000000
#define DNM_C_Flag_ImposeRotation				0x20000000
#define DNM_C_Flag_LockPlatform					0x40000000
#define DNM_C_Flag_ImposeTranslation			0x80000000

/* Dynamics End Flags */
#define DNM_C_EndFlag_BaseSize					0x00000001
#define DNM_C_EndFlag_AdvancedSize				0x00000002
#define DNM_C_EndFlag_ComplexSize				0x00000004
#define DNM_C_EndFlag_Reservated				0x00000008
#define DNM_C_EndFlag_MechanicChange			0x00000010
#define DNM_C_EndFlag_PlatformCrash				0x00000020
#define DNM_C_EndFlag_CanFall					0x00000040
#define DNM_C_EndFlag_Init						0x00000080
#define DNM_C_EndFlag_Spider					0x00000100
#define DNM_C_EndFlag_Shoot						0x00000200
#define DNM_C_EndFlag_SafeValid					0x00000400
#define DNM_C_EndFlag_ComputeInvertMatrix		0x00000800
#define DNM_C_EndFlag_ChangeScale				0x00001000
#define DNM_C_EndFlag_Exec						0x00002000
#define DNM_C_EndFlag_CollisionReport			0x00004000
#define DNM_C_EndFlag_NoGravity					0x00008000
#define DNM_C_EndFlag_Stop						0x00010000
#define DNM_C_EndFlag_SlidingGround				0x00020000
#define DNM_C_EndFlag_Always					0x00040000
#define DNM_C_EndFlag_Crash						0x00080000
#define DNM_C_EndFlag_Swim						0x00100000
#define DNM_C_EndFlag_NeverFall					0x00200000
#define DNM_C_EndFlag_Hanging					0x00400000
#define DNM_C_EndFlag_WallAdjust				0x00800000
#define DNM_C_EndFlag_ActorMove					0x01000000
#define DNM_C_EndFlag_ForceSafeWalk				0x02000000
#define DNM_C_EndFlag_DontUseNewMechanic		0x04000000