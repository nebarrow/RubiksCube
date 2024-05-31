cmake_minimum_required(VERSION 3.26)
project(laba8)

set(CMAKE_CXX_STANDARD 23)

set(GLEW_H /opt/homebrew/Cellar/glew/2.2.0_1/include)
set(GLFW_H /opt/homebrew/Cellar/glfw/3.4/include)
set(GLM_H /opt/homebrew/Cellar/glm/1.0.1/include)


include_directories(${GLEW_H} ${GLFW_H} ${GLM_H})

set(GLEW_LINK /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.4/lib/libglfw.3.4.dylib)
set(GLM_LINK /opt/homebrew/Cellar/glm/1.0.1/lib/libglm.dylib)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
add_executable(laba8 main.cpp utils/shaders.cpp utils/utility.cpp cube/cube.cpp cube/window.cpp)


target_link_libraries(laba8 ${OPENGL_LIBRARIES} ${GLEW_LINK} ${GLFW_LINK} ${GLM_LINK})
