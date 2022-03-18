#pragma once

#include <stddef.h>

#include "../LST.h"
#include "../MTH.h"
#include "../basedef.h"
#include "../apidef.h"


/*****************************************************************************
 *
 * IPT - Input module
 *
 *****************************************************************************/


typedef struct IPT_tdstInput IPT_tdstInput;
typedef struct IPT_tdstEntryElement IPT_tdstEntryElement;


ACP_VAR IPT_tdstInput *const IPT_g_stInputStructure;


typedef enum IPT_tdeDeviceEvent
{
	IPT_E_DeviceEvent_FirstDevice = 0x01,

	IPT_E_DeviceEvent_Keyboard = IPT_E_DeviceEvent_FirstDevice,
	IPT_E_DeviceEvent_Pad00,
	IPT_E_DeviceEvent_Pad01,
	IPT_E_DeviceEvent_Pad02,
	IPT_E_DeviceEvent_Pad03,
	IPT_E_DeviceEvent_Pad04,
	IPT_E_DeviceEvent_Pad05,
	IPT_E_DeviceEvent_Pad06,
	IPT_E_DeviceEvent_Pad07,
	IPT_E_DeviceEvent_Pad08,
	IPT_E_DeviceEvent_Pad09,
	IPT_E_DeviceEvent_Pad10,
	IPT_E_DeviceEvent_Pad11,
	IPT_E_DeviceEvent_Pad12,
	IPT_E_DeviceEvent_Pad13,
	IPT_E_DeviceEvent_Pad14,
	IPT_E_DeviceEvent_Pad15,
	IPT_E_DeviceEvent_Mouse,

	IPT_E_NbOfDeviceEvent
}
IPT_tdeDeviceEvent;

typedef enum IPT_tdePadEvent
{
	IPT_E_FirstPadAction = 0x00,

	IPT_E_PadUp = IPT_E_FirstPadAction,
	IPT_E_PadDown,
	IPT_E_PadLeft,
	IPT_E_PadRight,
	IPT_E_JoyXValue,
	IPT_E_JoyYValue,
	IPT_E_JoyZValue,
	IPT_E_JoyRValue,
	IPT_E_JoyUValue,
	IPT_E_JoyVValue,

	IPT_E_PadFirstButton,
	IPT_E_PadButton0 = IPT_E_PadFirstButton,
	IPT_E_PadButton1,
	IPT_E_PadButton2,
	IPT_E_PadButton3,
	IPT_E_PadButton4,
	IPT_E_PadButton5,
	IPT_E_PadButton6,
	IPT_E_PadButton7,
	IPT_E_PadButton8,
	IPT_E_PadButton9,
	IPT_E_PadButton10,
	IPT_E_PadButton11,
	IPT_E_PadButton12,
	IPT_E_PadButton13,
	IPT_E_PadButton14,
	IPT_E_PadButton15,
	IPT_E_PadButton16,
	IPT_E_PadButton17,
	IPT_E_PadButton18,
	IPT_E_PadButton19,
	IPT_E_PadButton20,
	IPT_E_PadButton21,
	IPT_E_PadButton22,
	IPT_E_PadButton23,
	IPT_E_PadButton24,
	IPT_E_PadButton25,
	IPT_E_PadButton26,
	IPT_E_PadButton27,
	IPT_E_PadButton28,
	IPT_E_PadButton29,
	IPT_E_PadButton30,
	IPT_E_PadButton31,
	IPT_E_PadLastButton = IPT_E_PadButton31,

	IPT_E_JoyFirstButton,
	IPT_E_JoyButton0 = IPT_E_JoyFirstButton,
	IPT_E_JoyButton1,
	IPT_E_JoyButton2,
	IPT_E_JoyButton3,
	IPT_E_JoyButton4,
	IPT_E_JoyButton5,
	IPT_E_JoyButton6,
	IPT_E_JoyButton7,
	IPT_E_JoyButton8,
	IPT_E_JoyButton9,
	IPT_E_JoyButton10,
	IPT_E_JoyButton11,
	IPT_E_JoyButton12,
	IPT_E_JoyButton13,
	IPT_E_JoyButton14,
	IPT_E_JoyButton15,
	IPT_E_JoyButton16,
	IPT_E_JoyButton17,
	IPT_E_JoyButton18,
	IPT_E_JoyButton19,
	IPT_E_JoyButton20,
	IPT_E_JoyButton21,
	IPT_E_JoyButton22,
	IPT_E_JoyButton23,
	IPT_E_JoyButton24,
	IPT_E_JoyButton25,
	IPT_E_JoyButton26,
	IPT_E_JoyButton27,
	IPT_E_JoyButton28,
	IPT_E_JoyButton29,
	IPT_E_JoyButton30,
	IPT_E_JoyButton31,
	IPT_E_JoyLastButton = IPT_E_JoyButton31,

	IPT_E_NbOfPadAndJoyAction,
}
IPT_tdePadEvent;

enum IPT_tdeEntryActionName
{
	IPT_EA_Action_Pad_AxeX,
	IPT_EA_Action_Pad_AxeY,
	IPT_EA_Action_Clavier_Haut,
	IPT_EA_Action_Clavier_Bas,
	IPT_EA_Action_Clavier_Droite,
	IPT_EA_Action_Clavier_Gauche,
	IPT_EA_Action_Clavier_Ralentir,
	IPT_EA_Action_Menu_Entrer,
	IPT_EA_Action_Menu_Annuler,
	IPT_EA_Action_Menu_Valider,
	IPT_EA_Action_Sauter,
	IPT_EA_Action_Tirer,
	IPT_EA_Pad_ButtonZ,
	IPT_EA_Action_Strafe,
	IPT_EA_Action_Nage_Plonger,
	IPT_EA_Action_Nage_Remonter,
	IPT_EA_Action_Camera_TourneDroite,
	IPT_EA_Action_Camera_TourneGauche,
	IPT_EA_Action_Camera_Look,
	IPT_EA_Action_Camera_Cut,
	IPT_EA_Action_CouperCinematique,
	IPT_EA_Action_TexteSuivant,
	IPT_EA_Action_AppelerMurphy,
	IPT_EA_Action_TransePolochus,
	IPT_EA_Action_Affiche_Jauge,
	IPT_EA_Action_BebeGlobox_1,
	IPT_EA_Action_BebeGlobox_2,
	IPT_EA_Action_StartCourseBonux,
	IPT_EA_CheatMurfy,
	IPT_EA_CheatElix,
	IPT_EA_CheatVignet,
	IPT_EA_CheatMorb20,
	IPT_EA_CheatGrappin,
	IPT_EA_CheatAccumulation,
	IPT_EA_CheatVie,
	IPT_EA_CheatLumz,
	IPT_EA_CheatCine,
	IPT_EA_CheatMap,
	IPT_EA_CheatShoot,
	IPT_EA_Select_Pad,
	IPT_EA_SpeedUp_Key,
	IPT_EA_Jump_Key,
	IPT_EA_LateralWalk_Key,
	IPT_EA_Paf_Key,
	IPT_EA_Jump_Pad,
	IPT_EA_LateralWalk_Pad,
	IPT_EA_Paf_Pad,
	IPT_EA_CamFollow_Pad,
	IPT_EA_Button_L,
	IPT_EA_Button_Start,
	IPT_EA_Button_PreviousMenu,
	IPT_EA_Button_Selection,
	IPT_EA_Button_XAnalogic,
	IPT_EA_Button_YAnalogic,
	IPT_EA_Button_LeftAnalogic,
	IPT_EA_Button_RightAnalogic,
	IPT_EA_Button_UpAnalogic,
	IPT_EA_Button_DownAnalogic,
	IPT_EA_Button_Paf,
	IPT_EA_Button_Jump,
	IPT_EA_Button_LateralWalk,
	IPT_EA_JoystickMoveOrder,
	IPT_EA_PAD_BoutonDroit,
	IPT_EA_Button_1,
	IPT_EA_Button_2,
	IPT_EA_Button_Left,
	IPT_EA_Button_Right,
	IPT_EA_Button_Up,
	IPT_EA_Button_Down,
	IPT_EA_Button_SpeedUp,
	IPT_EA_KeyboardMoveOrder,
	IPT_EA_MoveLeft,
	IPT_EA_MoveRight,
	IPT_EA_MoveUp,
	IPT_EA_MoveDown,
	IPT_EA_CamLeft_PAD,
	IPT_EA_CamRight_PAD,
	IPT_EA_BT_Camera_Look,
	IPT_EA_BT_Camera_LookRight,
	IPT_EA_BT_Camera_LookLeft,
	IPT_EA_BT_Camera_LookUp,
	IPT_EA_BT_Camera_LookDown,
	IPT_EA_Cam_Camera_TurnLeft,
	IPT_EA_Cam_Camera_TurnRight,
	IPT_EA_Cam_Camera_CutBehind,
	IPT_EA_Cam_Camera_SwitchMode,
	IPT_EA_Cam_pad_c,
	IPT_EA_Cam_pad_d,
	IPT_EA_Cam_Camera_Quake,
	IPT_EA_BT_Camera_Num1,
	IPT_EA_BT_Camera_Num2,
	IPT_EA_BT_Camera_Num6,
	IPT_EA_BT_Camera_Num7,
	IPT_EA_BT_Camera_Num8,
	IPT_EA_BT_Camera_Num9,
	IPT_EA_BT_Camera_IncDist,
	IPT_EA_BT_Camera_DecDist,
	IPT_EA_ClearOptionsDisplayed,
	IPT_EA_DisplayZDC,
	IPT_EA_ReinitTheMap,
	IPT_EA_ChooseLevel,
	IPT_EA_ChooseLevelUp,
	IPT_EA_ChooseLevelDown,
	IPT_EA_ChooseLevelValidate,
	IPT_EA_ChooseLevelInvalidate,
	IPT_EA_DisplayRaster,
	IPT_EA_DisplayRasterMode,
	IPT_EA_DisplayRasterPCU64,
	IPT_EA_DisplayModeToggle,
	IPT_EA_DisplayOnlyStatic,
	IPT_EA_DisplaySectorInfos,
	IPT_EA_DisplayWaypoints,
	IPT_EA_DisplayRayTraceSegments,
	IPT_EA_DisplayActivatedGendoors,
	IPT_EA_DisplayBoundingVolumes,
	IPT_EA_DisplayLight,
	IPT_EA_SnapShot,
	IPT_EA_DisplayTextOverScan,
	IPT_EA_AltDisplayTextOverScan,
	IPT_EA_GliMenu_Activate,
	IPT_EA_GliMenu_Next,
	IPT_EA_GliMenu_Prev,
	IPT_EA_GliMenu_Select,
	IPT_EA_GliMenu_Zoom,
	IPT_EA_GliMenu_Goto,
	IPT_EA_StartStopStep,
	IPT_EA_PulseStep,
	IPT_EA_FlyingMode,
	IPT_EA_FlyingModeForward,
	IPT_EA_FlyingModeBackward,
	IPT_EA_FlyingModeRight,
	IPT_EA_FlyingModeLeft,
	IPT_EA_FlyingModeUp,
	IPT_EA_FlyingModeDown,
	IPT_EA_FlyingModeStrafeRight,
	IPT_EA_FlyingModeStrafeLeft,
	IPT_EA_FlyingModeDoubleSpeed,
	IPT_EA_MemoryStackLog
};


typedef struct IPT_tdstHistoricElement
{
	BYTE bf2State;
	BYTE bf6DeviceType;
	BYTE ucCounter;
	short wDeviceValue;
}
IPT_tdstHistoricElement;

typedef struct IPT_tdstEntryElement
{
	DWORD ulNumberOfKeyWordElement;
	struct IPT_tdstKeyWordElement *d_stKeyWordElementArray; /* TODO: struct IPT_tdstKeyWordElement */

	char *p_szEntryName;
	int lState; /* Pos: Counter since pressed (LONG_MAX), Neg: Counter since released (LONG_MIN) */
	MTH_tdxReal xAnalogicValue;
	BOOL bIsActivate;
}
IPT_tdstEntryElement;

LST_M_DynamicListDecl(IPT_tdstEntryElement);


typedef struct IPT_tdstInput
{
	BYTE ucOnePadActivate;
	BYTE a_ucValideAndActiveDevice[IPT_E_NbOfDeviceEvent];
	/* Note: struct unknown, missing from source files */
	void *_a_hINODevice[IPT_E_NbOfDeviceEvent];

	BYTE a_ucKeyboardCounter[256];
	BYTE a_ucPadAndJoyCounter[IPT_E_NbOfDeviceEvent][IPT_E_NbOfPadAndJoyAction];
	BYTE ucKeyboardType;
	BYTE a_ucMouseButtonsCounter[9]; /* Unused? */

	BYTE _gap_06E8[24];
	
	DWORD ulNumberOfEntryElement;
	IPT_tdstEntryElement *d_stEntryElementArray;
	LST_M_DynamicAnchorTo(IPT_tdstEntryElement) hEntryElement; /* Unused? */

	short sEventHistoricSize;
	IPT_tdstHistoricElement *hEventHistoric;
}
IPT_tdstInput;
