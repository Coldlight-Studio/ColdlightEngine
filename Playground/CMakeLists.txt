if(CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
    set(CMAKE_SYSTEM_PROCESSOR "x86_64")
endif()
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/Playground")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

file(GLOB Playground_SRC "Source/*.cpp" "Source/*.h")
add_executable(Playground ${Playground_SRC})

target_compile_definitions(Playground PRIVATE
    $<$<CONFIG:Debug>:CL_DEBUG>
    $<$<CONFIG:Release>:CL_RELEASE>
    $<$<CONFIG:Shipping>:CL_SHIPPING>
)

target_link_libraries(Playground PRIVATE Engine)

if(WIN32)
    target_compile_definitions(Playground PRIVATE
        CL_PLATFORM_WINDOWS
    )
endif()

add_custom_command(
    TARGET Playground POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:Engine>"
        "$<TARGET_FILE_DIR:Playground>/Engine.dll"
    COMMENT "Copying Engine.dll to Playground output directory"
    VERBATIM
)