cmake_minimum_required(VERSION 3.12)
set(PICO_SDK_PATH "/usr/share/pico-sdk/")
set(PICO_BOARD "pico_w")
# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
include(pico_extras_import_optional.cmake)
project(pico_examples C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

include(example_auto_set_url.cmake)
# Add blink example

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()
add_subdirectory(blink)
add_subdirectory(button)
add_subdirectory(microdisp)
add_subdirectory(beep)
add_subdirectory(motion_sense)
add_subdirectory(temperature_sense)
add_subdirectory(bcd_count)
add_subdirectory(binary_count)
add_subdirectory(thermometer)
add_subdirectory(i2c_display)
add_subdirectory(interrupted)
