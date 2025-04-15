#pragma once

#include <Windows.h>

#ifdef CL_PLATFORM_WINDOWS
	#ifdef CL_CORE_API_EXPORTS
		#define CORE_API __declspec(dllexport)
	#else
		#define CORE_API __declspec(dllimport)
	#endif
#else
	#error Coldlight Engine only supports Windows!
#endif
