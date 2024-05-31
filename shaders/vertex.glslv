#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform mat4 MVP;
uniform mat4 transform;

void main() {
    gl_Position = MVP * vec4(position, 1.0);
}
