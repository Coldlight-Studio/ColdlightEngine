cmake_minimum_required(VERSION 3.20)
project(ColdlightEngine LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AVAILABLE_CONFIGS "Debug" "Release" "Shipping")

if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES "${AVAILABLE_CONFIGS}" CACHE STRING "Configs" FORCE)
else()
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${AVAILABLE_CONFIGS})
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
    endif()
endif()

add_subdirectory(Engine)
add_subdirectory(Playground)
