find_package(OpenGL REQUIRED)

add_executable(jstest_glfw main.c)

set_target_properties(jstest_glfw PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
target_link_libraries(jstest_glfw glfw ${OPENGL_LIBRARIES})

# just use raylib's copy of GLFW
target_include_directories(jstest_glfw PRIVATE ${raylib_SOURCE_DIR}/src/external/glfw/include)

