cmake_minimum_required(VERSION 3.12)
project(example)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
  set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
endif()

if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
  set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
endif()

# enable colors for ninja
set(CMAKE_COLOR_DIAGNOSTICS ON)

# set(CMAKE_BUILD_TYPE Debug)

add_compile_definitions(-DGL_SILENCE_DEPRECATION)
set_property(GLOBAL PROPERTY ALLOW_DUPLICATE_CUSTOM_TARGETS 1)

add_subdirectory(src/glfw)
add_subdirectory(src/raylib)

