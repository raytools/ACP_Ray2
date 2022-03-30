/****************************************************************************
 * Error list for BLT module
 ****************************************************************************/

#if !defined(M_DefineError)
#error You should define M_DefineError(name, msg) accordingly before including this file!
#else

	M_DefineError(BLT_E_StartOfFatal, "")

	M_DefineError(BLT_Err_AllocError, "Memory allocation error! NULL pointer returned")
	M_DefineError(BLT_Err_TooManyModules, "Too many modules, please increase BLT_C_MaxModules")

	M_DefineError(BLT_E_StartOfWarning, "")

	M_DefineError(BLT_Err_ModuleNotExist, "Module does not exist")
	M_DefineError(BLT_Err_UnknownErrType, "Trying to raise an unknown error type")
	M_DefineError(BLT_Err_MsgTooLong, "Error message is too long and will be truncated")
	M_DefineError(BLT_Err_NoErrTab, "Module's error table missing! Set error table first with BLT_fn_vModuleUseErrorTab")
	M_DefineError(BLT_Err_BadErrId, "Bad error ID - out of bounds of the module's error table")

	M_DefineError(BLT_E_StartOfInfo, "")

#undef M_DefineError
#endif
