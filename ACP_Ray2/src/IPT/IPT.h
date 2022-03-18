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
	IPT_E_Entry_Action_Pad_AxeX,
	IPT_E_Entry_Action_Pad_AxeY,
	IPT_E_Entry_Action_Clavier_Haut,
	IPT_E_Entry_Action_Clavier_Bas,
	IPT_E_Entry_Action_Clavier_Droite,
	IPT_E_Entry_Action_Clavier_Gauche,
	IPT_E_Entry_Action_Clavier_Ralentir,
	IPT_E_Entry_Action_Menu_Entrer,
	IPT_E_Entry_Action_Menu_Annuler,
	IPT_E_Entry_Action_Menu_Valider,
	IPT_E_Entry_Action_Sauter,
	IPT_E_Entry_Action_Tirer,
	IPT_E_Entry_Pad_ButtonZ,
	IPT_E_Entry_Action_Strafe,
	IPT_E_Entry_Action_Nage_Plonger,
	IPT_E_Entry_Action_Nage_Remonter,
	IPT_E_Entry_Action_Camera_TourneDroite,
	IPT_E_Entry_Action_Camera_TourneGauche,
	IPT_E_Entry_Action_Camera_Look,
	IPT_E_Entry_Action_Camera_Cut,
	IPT_E_Entry_Action_CouperCinematique,
	IPT_E_Entry_Action_TexteSuivant,
	IPT_E_Entry_Action_AppelerMurphy,
	IPT_E_Entry_Action_TransePolochus,
	IPT_E_Entry_Action_Affiche_Jauge,
	IPT_E_Entry_Action_BebeGlobox_1,
	IPT_E_Entry_Action_BebeGlobox_2,
	IPT_E_Entry_Action_StartCourseBonux,
	IPT_E_Entry_CheatMurfy,
	IPT_E_Entry_CheatElix,
	IPT_E_Entry_CheatVignet,
	IPT_E_Entry_CheatMorb20,
	IPT_E_Entry_CheatGrappin,
	IPT_E_Entry_CheatAccumulation,
	IPT_E_Entry_CheatVie,
	IPT_E_Entry_CheatLumz,
	IPT_E_Entry_CheatCine,
	IPT_E_Entry_CheatMap,
	IPT_E_Entry_CheatShoot,
	IPT_E_Entry_Select_Pad,
	IPT_E_Entry_SpeedUp_Key,
	IPT_E_Entry_Jump_Key,
	IPT_E_Entry_LateralWalk_Key,
	IPT_E_Entry_Paf_Key,
	IPT_E_Entry_Jump_Pad,
	IPT_E_Entry_LateralWalk_Pad,
	IPT_E_Entry_Paf_Pad,
	IPT_E_Entry_CamFollow_Pad,
	IPT_E_Entry_Button_L,
	IPT_E_Entry_Button_Start,
	IPT_E_Entry_Button_PreviousMenu,
	IPT_E_Entry_Button_Selection,
	IPT_E_Entry_Button_XAnalogic,
	IPT_E_Entry_Button_YAnalogic,
	IPT_E_Entry_Button_LeftAnalogic,
	IPT_E_Entry_Button_RightAnalogic,
	IPT_E_Entry_Button_UpAnalogic,
	IPT_E_Entry_Button_DownAnalogic,
	IPT_E_Entry_Button_Paf,
	IPT_E_Entry_Button_Jump,
	IPT_E_Entry_Button_LateralWalk,
	IPT_E_Entry_JoystickMoveOrder,
	IPT_E_Entry_PAD_BoutonDroit,
	IPT_E_Entry_Button_1,
	IPT_E_Entry_Button_2,
	IPT_E_Entry_Button_Left,
	IPT_E_Entry_Button_Right,
	IPT_E_Entry_Button_Up,
	IPT_E_Entry_Button_Down,
	IPT_E_Entry_Button_SpeedUp,
	IPT_E_Entry_KeyboardMoveOrder,
	IPT_E_Entry_MoveLeft,
	IPT_E_Entry_MoveRight,
	IPT_E_Entry_MoveUp,
	IPT_E_Entry_MoveDown,
	IPT_E_Entry_CamLeft_PAD,
	IPT_E_Entry_CamRight_PAD,
	IPT_E_Entry_BT_Camera_Look,
	IPT_E_Entry_BT_Camera_LookRight,
	IPT_E_Entry_BT_Camera_LookLeft,
	IPT_E_Entry_BT_Camera_LookUp,
	IPT_E_Entry_BT_Camera_LookDown,
	IPT_E_Entry_Cam_Camera_TurnLeft,
	IPT_E_Entry_Cam_Camera_TurnRight,
	IPT_E_Entry_Cam_Camera_CutBehind,
	IPT_E_Entry_Cam_Camera_SwitchMode,
	IPT_E_Entry_Cam_pad_c,
	IPT_E_Entry_Cam_pad_d,
	IPT_E_Entry_Cam_Camera_Quake,
	IPT_E_Entry_BT_Camera_Num1,
	IPT_E_Entry_BT_Camera_Num2,
	IPT_E_Entry_BT_Camera_Num6,
	IPT_E_Entry_BT_Camera_Num7,
	IPT_E_Entry_BT_Camera_Num8,
	IPT_E_Entry_BT_Camera_Num9,
	IPT_E_Entry_BT_Camera_IncDist,
	IPT_E_Entry_BT_Camera_DecDist,
	IPT_E_Entry_ClearOptionsDisplayed,
	IPT_E_Entry_DisplayZDC,
	IPT_E_Entry_ReinitTheMap,
	IPT_E_Entry_ChooseLevel,
	IPT_E_Entry_ChooseLevelUp,
	IPT_E_Entry_ChooseLevelDown,
	IPT_E_Entry_ChooseLevelValidate,
	IPT_E_Entry_ChooseLevelInvalidate,
	IPT_E_Entry_DisplayRaster,
	IPT_E_Entry_DisplayRasterMode,
	IPT_E_Entry_DisplayRasterPCU64,
	IPT_E_Entry_DisplayModeToggle,
	IPT_E_Entry_DisplayOnlyStatic,
	IPT_E_Entry_DisplaySectorInfos,
	IPT_E_Entry_DisplayWaypoints,
	IPT_E_Entry_DisplayRayTraceSegments,
	IPT_E_Entry_DisplayActivatedGendoors,
	IPT_E_Entry_DisplayBoundingVolumes,
	IPT_E_Entry_DisplayLight,
	IPT_E_Entry_SnapShot,
	IPT_E_Entry_DisplayTextOverScan,
	IPT_E_Entry_AltDisplayTextOverScan,
	IPT_E_Entry_GliMenu_Activate,
	IPT_E_Entry_GliMenu_Next,
	IPT_E_Entry_GliMenu_Prev,
	IPT_E_Entry_GliMenu_Select,
	IPT_E_Entry_GliMenu_Zoom,
	IPT_E_Entry_GliMenu_Goto,
	IPT_E_Entry_StartStopStep,
	IPT_E_Entry_PulseStep,
	IPT_E_Entry_FlyingMode,
	IPT_E_Entry_FlyingModeForward,
	IPT_E_Entry_FlyingModeBackward,
	IPT_E_Entry_FlyingModeRight,
	IPT_E_Entry_FlyingModeLeft,
	IPT_E_Entry_FlyingModeUp,
	IPT_E_Entry_FlyingModeDown,
	IPT_E_Entry_FlyingModeStrafeRight,
	IPT_E_Entry_FlyingModeStrafeLeft,
	IPT_E_Entry_FlyingModeDoubleSpeed,
	IPT_E_Entry_MemoryStackLog
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
