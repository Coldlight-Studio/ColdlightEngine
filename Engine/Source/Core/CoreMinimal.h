#pragma once

#if CL_PLATFORM_WINDOWS
    #ifdef CL_CORE_API_EXPORTS
        #define CORE_API __declspec(dllexport)
    #else
        #define CORE_API __declspec(dllimport)
    #endif
#elif CL_PLATFORM_APPLE || CL_PLATFORM_LINUX
    #ifdef CL_CORE_API_EXPORTS
        #define CORE_API __attribute__((visibility("default")))
    #else
        #define CORE_API
    #endif
#else
    #error "Coldlight Engine only supports Windows, macOS, and Linux!"
#endif