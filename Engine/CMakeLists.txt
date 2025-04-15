if(CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
    set(CMAKE_SYSTEM_PROCESSOR "x86_64")
endif()
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/Engine")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

file(GLOB_RECURSE Engine_SRC "Source/*.cpp" "Source/*.h")

add_library(Engine SHARED ${Engine_SRC})
target_include_directories(Engine PUBLIC 
    "Source"
)
target_precompile_headers(Engine PUBLIC "Source/clpch.h")

target_compile_definitions(Engine PRIVATE
    $<$<CONFIG:Debug>:CL_DEBUG>
    $<$<CONFIG:Release>:CL_RELEASE>
    $<$<CONFIG:Shipping>:CL_SHIPPING>
)

if(WIN32)
    target_compile_definitions(Engine PRIVATE
        CL_PLATFORM_WINDOWS
        CL_CORE_API_EXPORTS
        _WINDLL
    )
    set_target_properties(Engine PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
elseif(APPLE)
    target_compile_definitions(Engine PRIVATE
        CL_PLATFORM_APPLE
    )
    set_target_properties(Engine PROPERTIES
        MACOSX_RPATH ON
        XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++20"
        XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++"
    )
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(Engine PRIVATE
        CL_PLATFORM_LINUX
    )
    set_target_properties(Engine PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        CXX_VISIBILITY_PRESET "hidden"
        VISIBILITY_INLINES_HIDDEN ON
    )
endif()