#pragma once

#define CALLBACK __stdcall

#ifdef ACPRAY2_EXPORTS
#define ACP_API __declspec(dllexport)
#else
#define ACP_API __declspec(dllimport)
#endif
