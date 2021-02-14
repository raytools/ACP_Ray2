#pragma once

#ifdef ACPRAY2_EXPORTS
#define ACP_API __declspec(dllexport)
#else
#define ACP_API __declspec(dllimport)
#endif
