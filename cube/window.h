#ifndef LABA8_WINDOW_H
#define LABA8_WINDOW_H

#include <GLFW/glfw3.h>
class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();
    GLFWwindow* getWindow() const;
    void start() const;
    bool shouldClose() const;
    void pollEvents() const;
    void swapBuffers() const;

private:
    GLFWwindow* window;
};
#endif

