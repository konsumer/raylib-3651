#include <GLFW/glfw3.h>
#include <stdbool.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#define SPEED 0.005f

GLFWwindow *window = NULL;

float getRed() {
  static float red = 0.0f;
  static bool increase = true;

  if (increase) {
    red += SPEED;
    if (red > 1.0f) {
      red = 1.0f;
      increase = false;
    }
  } else {
    red -= SPEED;
    if (red < 0.0f) {
      red = 0.0f;
      increase = true;
    }
  }

  return red;
}

void mainLoop() {
  glClearColor(getRed(), 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);
  glfwPollEvents();
}

int main() {
  if (!glfwInit()) {
    return 0;
  }

  window = glfwCreateWindow(640, 480, "jstest", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

#ifdef EMSCRIPTEN
  emscripten_set_main_loop(&mainLoop, 0, 1);
#else
  while (!glfwWindowShouldClose(window)) {
    mainLoop();
  }
#endif

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
