#include "cube.h"
#include "window.h"
#include "../utils/utility.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    Utility::key_callback(window, key, scancode, action, mode);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    Utility::mouse_callback(window, xpos, ypos);
}

void catchEvents(GLFWwindow* window) {
    Utility::camera(window);
    Cube::movement(window);
}

Window::Window(int width, int height, const char* title) {
    if (!glfwInit()) {
        return;
    }
    if (!getWindow()) {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return;
    }

    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
    glViewport(0, 0, framebufferWidth, framebufferHeight);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}


Window::~Window() {
    glfwTerminate();
}

GLFWwindow* Window::getWindow() const {
    return window;
}

void Window::start() const {

    glfwSetKeyCallback(getWindow(), key_callback);
    glfwSetCursorPosCallback(getWindow(), mouse_callback);
    while (!shouldClose()) {
        pollEvents();
        catchEvents(getWindow());
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        Cube::drawScene();
        swapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::pollEvents() const {
    glfwPollEvents();
}

void Window::swapBuffers() const {
    glfwSwapBuffers(window);
}