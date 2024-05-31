#include "utility.h"
#include <glm/glm.hpp>

glm::vec3 Utility::cameraPos = glm::vec3(0.5f, 2.0f, 6.0f);
glm::vec3 Utility::cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 Utility::cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
bool Utility::keys[1024] = { false };
float Utility::yaw = -90.0f;
float Utility::pitch = 0.0f;
float Utility::lastX = 400;
float Utility::lastY = 300;
bool Utility::firstMouse = true;

Utility::Utility(GLFWwindow* window) : window(window) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Utility::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xOffSet = xpos - lastX;
    GLfloat yOffSet = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    GLfloat sensitivity = 0.05f;
    xOffSet *= sensitivity;
    yOffSet *= sensitivity;

    yaw += xOffSet;
    pitch += yOffSet;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

void Utility::key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (action == GLFW_PRESS) {
        keys[key] = true;
    } else if (action == GLFW_RELEASE) {
        keys[key] = false;
    }
}

void Utility::camera(GLFWwindow *window) {
    GLfloat cameraSpeed = 0.05f;
    if (keys[GLFW_KEY_ESCAPE]) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (keys[GLFW_KEY_W])
        cameraPos += cameraFront * cameraSpeed;
    if (keys[GLFW_KEY_S])
        cameraPos -= cameraFront * cameraSpeed;
    if (keys[GLFW_KEY_A])
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (keys[GLFW_KEY_D])
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
