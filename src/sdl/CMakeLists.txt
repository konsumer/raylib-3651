add_executable(jstest_sdl main.c)

find_package(SDL2 REQUIRED)
target_link_libraries(jstest_sdl SDL2::SDL2)

if (EMSCRIPTEN)
  set_target_properties(jstest_sdl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/docs/"
    SUFFIX ".mjs"
    LINK_FLAGS "-Oz -sSINGLE_FILE -sASYNCIFY -s USE_SDL=2"
  )
else()
  set_target_properties(jstest_sdl PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()
