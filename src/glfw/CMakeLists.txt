add_custom_command(
  OUTPUT src/glfw/vertex.h
  COMMAND xxd -i src/glfw/vertex.glsl > src/glfw/vertex.h
  DEPENDS src/glfw/vertex.glsl
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_command(
  OUTPUT src/glfw/fragment.h
  COMMAND xxd -i src/glfw/fragment.glsl > src/glfw/fragment.h
  DEPENDS src/glfw/fragment.glsl
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(jstest_glfw main.c vertex.h fragment.h)

if(EMSCRIPTEN)
  set_target_properties(jstest_glfw PROPERTIES
    LINK_FLAGS "-Oz -sSINGLE_FILE -sUSE_GLFW=3 -sFULL_ES3"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/docs/"
    SUFFIX ".mjs"
  )

else()
  find_package(OpenGL REQUIRED)
  target_include_directories(jstest_glfw PRIVATE ${raylib_SOURCE_DIR}/src/external/glfw/include)
  set_target_properties(jstest_glfw PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
  target_link_libraries(jstest_glfw glfw ${OPENGL_LIBRARIES})
endif()
