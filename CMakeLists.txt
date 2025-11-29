cmake_minimum_required(VERSION 3.20)
project(aoc)

set(EXE_NAME ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(TARGET_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGET_DIR})

# YouCompleteMe completion setup - based on https://github.com/danebulat/vim-cmake-boilerplate
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


file(GLOB DAY_SOURCES "src/day*.cpp")
add_executable(${EXE_NAME}
    "src/main.cpp"
    "src/harness.cpp"
    "src/colours.cpp"
    ${DAY_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    DEBUG_OUTPUT_NAME ${EXE_NAME}d
    RELWITHDEBINFO_OUTPUT_NAME ${EXE_NAME}rd)

target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_precompile_headers(${EXE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/pch.h)

# YouCompleteMe completion setup - based on https://github.com/danebulat/vim-cmake-boilerplate
# add compiler warning flags just when building this project
# via the BUILD_INTERFACE generator expression
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(gcc_flags "-Wall;-Wextra;-Wshadow;-Wshadow;-Wformat=2;-Werror")
set(msvc_flags "-W3")

target_compile_options(${EXE_NAME} PRIVATE
   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")
