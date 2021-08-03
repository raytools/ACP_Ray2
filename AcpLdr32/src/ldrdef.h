#pragma once

#define CALLBACK __stdcall

#ifdef ACPLDR32_EXPORTS
#define LDR_API __declspec(dllexport)
#else
#define LDR_API __declspec(dllimport)
#endif
