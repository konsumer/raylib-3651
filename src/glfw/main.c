#include <GLFW/glfw3.h>
#include "vertex.h"
#include "fragment.h"
#include <stdio.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#include <GLES3/gl3.h>
#else
#include <OpenGL/gl3.h>
#endif

GLuint shaderProgram;
GLFWwindow* window;
GLuint VBO, EBO;
GLint buttonValues[20] = {0};

// Utility function to compile shader
GLuint compileShader(const unsigned char* source, size_t length, GLenum type) {
    GLuint shader = glCreateShader(type);
    const char* src = (const char*)source;
    glShaderSource(shader, 1, &src, (GLint*)&length);
    glCompileShader(shader);

    // Check for compilation errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Shader compilation error: %s\n", infoLog);
        return 0;
    }
    return shader;
}

void checkOpenGLError(const char* stmt, const char* fname, int line)
{
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
    {
        printf("OpenGL error %08x, at %s:%i - for %s\n", err, fname, line, stmt);
    }
}

void mainLoop() {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);

    // Update uniforms
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glUniform2f(glGetUniformLocation(shaderProgram, "iResolution"), (float)width, (float)height);
    glUniform1i(glGetUniformLocation(shaderProgram, "jsButtonCount"), 10);
    glUniform1iv(glGetUniformLocation(shaderProgram, "jsButtonValues"), 20, buttonValues);

    // Draw
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    // Set up vertex attributes each frame
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(320, 240, "jstester", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Compile and link shaders
    GLuint vertexShader = compileShader(src_glfw_vertex_glsl, src_glfw_vertex_glsl_len, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(src_glfw_fragment_glsl, src_glfw_fragment_glsl_len, GL_FRAGMENT_SHADER);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("Shader program linking error: %s\n", infoLog);
        return -1;
    }

    float vertices[] = {
        // Position         // Texture coords
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3
    };

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window)) {
        mainLoop();
    }

    // Cleanup
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}
