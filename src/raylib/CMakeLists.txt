include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/heads/master.zip)
FetchContent_MakeAvailable(raylib)

# this requires -DPLATFORM=GLFW on CLI
add_executable(jstest_raylib_glfw main.c)
target_link_libraries(jstest_raylib_glfw PUBLIC raylib)

# this requires -DPLATFORM=SDL on CLI
add_executable(jstest_raylib_sdl main.c)
target_link_libraries(jstest_raylib_sdl PUBLIC raylib)


if (EMSCRIPTEN)
  set_target_properties(jstest_raylib_sdl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/docs/"
    SUFFIX ".mjs"
  )
  set_target_properties(jstest_raylib_glfw PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/docs/"
    SUFFIX ".mjs"
  )
  if("${PLATFORM}" STREQUAL "SDL")
    set_target_properties(jstest_raylib_sdl PROPERTIES
      LINK_FLAGS "-Oz -sSINGLE_FILE -sASYNCIFY -s USE_SDL=2"
    )
  else()
    set_target_properties(jstest_raylib_glfw PROPERTIES
      LINK_FLAGS "-Oz -sSINGLE_FILE -sASYNCIFY -sUSE_GLFW=3"
    )
  endif()
else()
  set_target_properties(jstest_raylib_sdl PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
  set_target_properties(jstest_raylib_glfw PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()
