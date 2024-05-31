#ifndef LABA8_UTILITY_H
#define LABA8_UTILITY_H

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Utility {
public:
    Utility(GLFWwindow *window);
    static glm::vec3 cameraPos;
    static glm::vec3 cameraFront;
    static glm::vec3 cameraUp;
    static glm::vec3 targetPos;
    static bool keys[1024];
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void mouse_callback(GLFWwindow *window, double xpos, double ypos);
    static void camera(GLFWwindow* window);
    static void updateCameraPos();

private:
    GLFWwindow *window;
    static float yaw;
    static float pitch;
    static float lastX;
    static float lastY;
    static bool firstMouse;

};
#endif
